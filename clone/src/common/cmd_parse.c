/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:40:18 by math              #+#    #+#             */
/*   Updated: 2023/03/16 08:45:39 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int32_t	count_arg_char(char *cmd)
{
	int32_t	i;

	i = 1;
	if (*cmd == '"')
	{
		while (cmd[i])
		{
			if (cmd[i] == '"' && cmd[i - 1] != '\\')
				return (i + 1);
			i++;
		}
	}
	else if (*cmd == '\'')
	{
		while (cmd[i])
		{
			if (cmd[i] == '\'' && cmd[i - 1] != '\\')
				return (i + 1);
			i++;
		}
	}
	else
		while (cmd[i] && cmd[i] != ' ')
			i++;
	return (i);
}

static char	**get_args(char *str, char *cmd)
{
	int32_t	count;
	t_lst	*lst;
	char	*dest;

	str = get_cmd_end(str);
	lst = lst_new(10, sizeof(char *));
	count = 0;
	lst_add(lst, cmd);
	while (str[count])
	{
		str = get_arg_start(str);
		count = count_arg_char(str);
		dest = malloc(count + 1);
		if (dest == NULL)
			return (lst_free(lst), free_err_exit(STDERR_FILENO));
		dest[count] = '\0';
		if (count >= 2 && str[0] == '"' && str[count - 1] == '"')
			lst_add(lst, ft_strncpy(dest, &str[1], count - 2));
		else if (count >= 2 && str[0] == '\'' && str[count - 1] == '\'')
			lst_add(lst, ft_strncpy(dest, &str[1], count - 2));
		else
			lst_add(lst, ft_strncpy(dest, str, count));
	}
	lst_add(lst, NULL);
	return (lst_free_to_array(lst));
}

/// @brief can parse string inside string with double quote or single quote
/// while parsing more complex command ft_split failed.
/// @param proc
/// @param cmds
/// @param i
/// @param cmd
/// @return
static void	*parse_cmd(t_proc *proc, t_cmd **cmds, int32_t i, char *cmd)
{
	cmds[i] = malloc(sizeof(t_cmd));
	if (cmds[i] == NULL)
		return (free_err_exit(STDERR_FILENO));
	cmd = get_cmd_start(cmd);
	cmds[i]->cmd = get_cmd(cmd);
	cmds[i]->args = get_args(cmd, cmds[i]->cmd);
	cmds[i]->full_path_cmd = get_full_path_cmd(proc, cmds[i]);
	cmds[i]->args[0] = cmds[i]->full_path_cmd;
	cmds[i]->error = false;
	proc->error = false;
	proc->command_found = true;
	if (!cmds[i]->full_path_cmd)
	{
		write_msg(STDERR_FILENO, "Command not found: ");
		write_msg(STDERR_FILENO, proc->cmds[i]->cmd);
		write_msg(STDERR_FILENO, "\n");
		proc->command_found = false;
	}
	return (NULL);
}

t_cmd	**parse_cmds(t_proc *proc, char **argv, int32_t count)
{
	t_cmd	**cmds;
	int32_t	i;

	i = 0;
	cmds = malloc(sizeof(t_cmd *) * (count + 1));
	if (cmds == NULL)
		return (free_err_exit(STDERR_FILENO));
	proc->cmds = cmds;
	proc->error = false;
	while (i < proc->cmds_count)
	{
		parse_cmd(proc, cmds, i, argv[i]);
		i++;
	}
	cmds[i] = NULL;
	return (cmds);
}

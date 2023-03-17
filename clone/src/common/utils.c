/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:40:18 by math              #+#    #+#             */
/*   Updated: 2023/03/16 10:35:27 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	unlink_fifo(char *f_name)
{
	if (unlink((const char *)f_name) != 0)
	{
		perror("unlink error.");
		write_msg(STDERR_FILENO, f_name);
		write_msg(STDERR_FILENO, "\n");
		free_err_exit(EXIT_FAILURE);
	}
}

char	*get_full_path_cmd(t_proc *proc, t_cmd *command)
{
	int32_t	i;
	char	*path;
	char	*cmd;

	i = 0;
	cmd = command->cmd;
	if (proc->paths == NULL)
		return (NULL);
	if (cmd[0] == '/' && access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	while (proc->paths[i])
	{
		path = ft_strjoin_temp(proc->paths[i], "/");
		path = ft_strjoin(path, cmd);
		if (access(path, F_OK | X_OK) == 0)
		{
			command->full_path_cmd = path;
			return (path);
		}
		free(path);
		i++;
	}
	return (NULL);
}

char	*parse_pwd(char **envp)
{
	int32_t	i;

	if (!envp || !*envp)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PWD=", 4) != 0)
		{
			if (*(envp[i] + 4) == '/' && *(envp[i] + 5) == '\0')
				return (ft_strdup(""));
			else
				return (ft_strjoin(envp[i] + 4, "/"));
		}
		i++;
	}
	i = 0;
	return (NULL);
}

char	**parse_paths(char **envp)
{
	char	**paths;
	int32_t	i;

	paths = NULL;
	if (!envp || !*envp)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 4) != 0)
		{
			paths = ft_split(envp[i] + 5, ':');
			break ;
		}
		i++;
	}
	i = 0;
	return (paths);
}

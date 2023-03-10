/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:40:18 by math              #+#    #+#             */
/*   Updated: 2023/03/10 14:19:13 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	unlink_fifo(char *f_name)
{
	if (unlink((const char *)f_name) != 0)
	{
		free_all();
		perror("unlink() error");
	}
}

char	*get_full_path_cmd(t_proc *proc, char *cmd)
{
	int32_t	i;
	char	*path;

	i = 0;
	if (proc->paths == NULL)
		return (NULL);
	if (cmd[0] == '/' && access(cmd, F_OK) == 0)
		return (ft_strdup(cmd));
	while (proc->paths[i])
	{
		path = ft_strjoin_temp(proc->paths[i], "/");
		path = ft_strjoin(path, cmd);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
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
	return (paths);
}

int32_t	open_files(t_proc *proc)
{
	proc->here_doc = false;
	proc->f_out = open(proc->f_out_name, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (proc->f_out == -1)
	{
		proc->f_out = 1;
		write_error(2, true);
	}
	proc->f_in = open(proc->f_in_name, O_RDONLY, 0777);
	if (proc->f_in == -1)
	{
		proc->f_in = 0;
		write_error(2, false);
		write_msg(proc->f_in_name, 2, true);
	}
	dup2(proc->f_in, STDIN_FILENO);
	return (proc->f_out);
}

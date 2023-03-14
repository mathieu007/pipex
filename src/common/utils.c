/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:40:18 by math              #+#    #+#             */
/*   Updated: 2023/03/13 19:20:08 by math             ###   ########.fr       */
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
			return (ft_strjoin(envp[i] + 4, "/"));
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

static void	open_unexisting_file(t_proc *proc)
{
	write_msg(2, strerror(errno));
	write_msg(2, ": ");
	write_msg(2, proc->f_in_name);
	proc->f_in = open(proc->f_in_name, O_RDONLY | O_CREAT | O_TRUNC, 0777);
	if (proc->f_in == -1)
		free_exit(EXIT_FAILURE);
	proc->waitpid = WNOHANG;
	proc->f_in_not_exist = true;
	write_msg(2, "\n");
}

int32_t	open_files(t_proc *proc)
{
	proc->here_doc = false;
	proc->waitpid = 0;
	proc->f_out = open(proc->f_out_name, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (proc->f_out == -1)
	{
		proc->waitpid = WNOHANG;
		write_msg(2, strerror(errno));
		write_msg(2, proc->f_out_name);
		write_msg(2, "\n");
		free_exit(EXIT_FAILURE);
	}
	proc->f_in = open(proc->f_in_name, O_RDWR, 0777);
	proc->f_in_not_exist = false;
	if (proc->f_in == -1)
		open_unexisting_file(proc);
	dup2(proc->f_out, STDOUT_FILENO);
	dup2(proc->f_in, STDIN_FILENO);
	close(proc->f_out);
	close(proc->f_in);
	return (proc->f_out);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 07:57:14 by mroy              #+#    #+#             */
/*   Updated: 2023/03/10 17:01:42 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/// @brief Very important use WNOHANG: no hang in wait
/// @param proc
/// @param i
void	child_process(t_proc *proc, int32_t i)
{
	pid_t	pid;
	int32_t	status;

	pid = fork();
	if (pid == -1)
		error_exit(NULL, 2, true, 1);
	if (pid == 0)
	{
		if (i - 1 != -1)
		{
			dup2(proc->cmds[i - 1]->file_in, STDIN_FILENO);
			close(proc->cmds[i - 1]->file_in);
			close(proc->cmds[i - 1]->file_out);
		}
		if (i + 1 < proc->cmds_count)
		{
			close(proc->cmds[i]->file_in);
			dup2(proc->cmds[i]->file_out, STDOUT_FILENO);
			close(proc->cmds[i]->file_out);
		}
		execute(proc, i);
	}
	else
	{
		if (i - 1 != -1)
		{
			close(proc->cmds[i - 1]->file_in);
			close(proc->cmds[i - 1]->file_out);
		}
		close(proc->cmds[i]->file_out);
		dup2(proc->cmds[i]->file_in, STDIN_FILENO);
		waitpid(pid, &status, WNOHANG);
	}
}

void	pipe_childs(t_proc *proc)
{
	int32_t	i;
	int32_t	fds[2];

	i = 0;
	while (i < proc->cmds_count - 1)
	{
		if (pipe(fds) == -1)
			error_exit(NULL, 2, true, 1);
		proc = init_fds(fds, i);
		i++;
	}
}

void	exec_childs(t_proc *proc)
{
	int32_t	i;

	i = 0;
	while (i < proc->cmds_count - 1)
	{
		child_process(proc, i);
		i++;
	}
}

void	execute(t_proc *proc, int32_t i)
{
	char	*fp_cmd;

	if (!proc->paths)
	{
		write_msg("Command not found:", 2, false);
		write_msg(proc->cmds[i]->cmd, 2, true);
		error_exit(NULL, 2, false, 1);
	}
	fp_cmd = get_full_path_cmd(proc, proc->cmds[i]->cmd);
	if (!fp_cmd)
	{
		write_msg("Command not found:", 2, false);
		write_msg(proc->cmds[i]->cmd, 2, true);
		error_exit(NULL, 2, false, 1);
	}
	if (execve(fp_cmd, proc->cmds[i]->args, proc->envp) == -1)
		error_exit("Could not execve.", 2, true, 1);
	free(fp_cmd);
	error_exit("Could not execve.", 2, true, 1);
}

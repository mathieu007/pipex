/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 07:57:14 by mroy              #+#    #+#             */
/*   Updated: 2023/03/16 12:19:19 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipe_childs(t_proc *proc)
{
	int32_t	i;
	int32_t	fds[2];

	i = 0;
	while (i < proc->cmds_count)
	{
		if (!proc->cmds[i]->error)
		{
			if (pipe(fds) == -1)
			{
				write_msg(STDERR_FILENO, strerror(errno));
				free_exit(EXIT_FAILURE);
			}
			init_fds(fds, i);
		}
		i++;
	}
}

void	fork_first_child(t_proc *proc, int32_t i)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		write_msg(STDERR_FILENO, strerror(errno));
		free_exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		dup2(proc->cmds[i]->file_out, STDOUT_FILENO);
		close(proc->cmds[i]->file_out);
		close(proc->cmds[i]->file_in);
		execute(proc, i);
	}
	proc->cmds[i]->pid = pid;
}

void	fork_single_child(t_proc *proc, int32_t i)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		write_msg(STDERR_FILENO, strerror(errno));
		free_exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		dup2(proc->cmds[i]->file_in, STDIN_FILENO);
		close(proc->cmds[i]->file_out);
		close(proc->cmds[i]->file_in);
		close(proc->f_in);
		close(proc->f_out);
		execute(proc, i);
	}
	proc->cmds[i]->pid = pid;
}

void	fork_last_child(t_proc *proc, int32_t i)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		write_msg(STDERR_FILENO, strerror(errno));
		free_exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		dup2(proc->cmds[i - 1]->file_in, STDIN_FILENO);
		close(proc->cmds[i - 1]->file_in);
		close(proc->cmds[i - 1]->file_out);
		close(proc->cmds[i]->file_in);
		close(proc->cmds[i]->file_out);
		execute(proc, i);
	}
	close(proc->cmds[i - 1]->file_in);
	close(proc->cmds[i - 1]->file_out);
	close(proc->cmds[i]->file_in);
	close(proc->cmds[i]->file_out);
	close(proc->f_in);
	close(proc->f_out);
	proc->cmds[i]->pid = pid;
}

void	fork_middle_child(t_proc *proc, int32_t i)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		write_msg(STDERR_FILENO, strerror(errno));
		free_exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		dup2(proc->cmds[i - 1]->file_in, STDIN_FILENO);
		dup2(proc->cmds[i]->file_out, STDOUT_FILENO);
		close(proc->cmds[i]->file_out);
		close(proc->cmds[i - 1]->file_in);
		close(proc->cmds[i - 1]->file_out);
		execute(proc, i);
	}
	close(proc->cmds[i - 1]->file_in);
	close(proc->cmds[i - 1]->file_out);
	close(proc->cmds[i]->file_out);
	proc->cmds[i]->pid = pid;
}

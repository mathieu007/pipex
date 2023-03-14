/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 07:57:14 by mroy              #+#    #+#             */
/*   Updated: 2023/03/13 22:08:39 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int32_t count_valid_cmd(t_proc *proc)
{
	int32_t	i;
	int32_t	count;

	i = 0;
	count = 0;
	while (i < proc->cmds_count)
	{
		if (!proc->cmds[i]->error)
			count++;
		i++;
	}
	return (count);
}

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

static void	fork_first_child(t_proc *proc)
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
		dup2(proc->cmds[0]->file_out, STDOUT_FILENO);
		close(proc->cmds[0]->file_out);
		close(proc->cmds[0]->file_in);
		close(proc->cmds[1]->file_out);
		close(proc->cmds[1]->file_in);
		execute(proc, 0);
	}
	proc->cmds[0]->pid = pid;
}

static void	fork_single_child(t_proc *proc, int32_t i)
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

static void	fork_last_child(t_proc *proc, int32_t i)
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
		close(proc->f_in);
		close(proc->f_out);
		execute(proc, i);
	}
	proc->cmds[i]->pid = pid;
}

static void	fork_middle_child(t_proc *proc, int32_t i)
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
		close(proc->cmds[i - 1]->file_in);
		close(proc->cmds[i - 1]->file_out);
		close(proc->cmds[i]->file_in);
		close(proc->cmds[i]->file_out);
		execute(proc, i);
	}
	proc->cmds[i]->pid = pid;
}

static void	wait_childs(t_proc *proc)
{
	int32_t	i;
	pid_t	child;
	int32_t	status;

	i = 0;
	while (i < proc->cmds_count)
	{
		if (!proc->cmds[i]->error)
		{
			child = proc->cmds[i]->pid;
			if (ft_strncmp(proc->cmds[i]->cmd, "sleep", 5) == 0)
				waitpid(child, &status, 0);
			else
				waitpid(child, &status, WNOHANG);
		}
		i++;
	}
}

void	exec_childs(t_proc *proc)
{
	int32_t	i;
	int32_t	count;

	i = 0;
	count = count_valid_cmd(proc);
	while (i < proc->cmds_count)
	{
		if (!proc->cmds[i]->error)
		{
			if (count == 1)
				fork_single_child(proc, i);
			else if (i == 0)
				fork_first_child(proc);
			else if (i == proc->cmds_count - 1)
				fork_last_child(proc, i);
			else
				fork_middle_child(proc, i);
		}
		i++;
	}
	wait_childs(proc);
}

void	execute(t_proc *proc, int32_t i)
{
	if (!proc->paths)
	{
		write_msg(STDERR_FILENO, "Environement path error.\n");
		write_msg(STDERR_FILENO, "Command not found: ");
		write_msg(STDERR_FILENO, proc->cmds[i]->cmd);
		write_msg(STDERR_FILENO, "\n");
		free_exit(EXIT_FAILURE);
	}
	if (execve(proc->cmds[i]->full_path_cmd, proc->cmds[i]->args, proc->envp) == -1)
	{
		write_msg(STDERR_FILENO, "Could not execve command: ");
		write_msg(STDERR_FILENO, proc->cmds[i]->cmd);
		write_msg(STDERR_FILENO, "\n");
		free_exit(EXIT_FAILURE);
	}
}

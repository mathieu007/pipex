/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 07:57:14 by mroy              #+#    #+#             */
/*   Updated: 2023/03/16 10:45:42 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int32_t	count_valid_cmd(t_proc *proc)
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

static void	wait_childs(t_proc *proc)
{
	int32_t	i;
	int32_t	status;
	pid_t	pid;

	i = 0;
	while (i < proc->cmds_count)
	{
		if (!proc->cmds[i]->error && proc->command_found)
		{
			pid = proc->cmds[i]->pid;
			waitpid(pid, &status, 0);
		}
		i++;
	}
}

// static int32_t	child_has_exit(t_proc *proc, int32_t i)
// {
// 	int32_t	status;
// 	pid_t	result;

// 	if (proc->cmds[i]->pid != 0)
// 	{
// 		result = waitpid(proc->cmds[i]->pid, &status, WNOHANG);
// 		if (result == -1)
// 		{
// 			perror("waitpid error.");
// 			free_exit(EXIT_FAILURE);
// 		}
// 		else if (result == proc->cmds[i]->pid || status > 0)
// 		{
// 			// if (WIFSIGNALED(status) || WIFEXITED(status))
// 			proc->cmds[i]->pid = 0;
// 			return (1);
// 		}
// 		return (0);
// 	}
// 	return (1);
// }
// /// @brief should use a usleep, but not allowed
// /// @param proc
// static void	wait_child(t_proc *proc)
// {
// 	int32_t	i;
// 	int32_t	count_valid_child;
// 	int32_t	child_exit;

// 	count_valid_child = count_valid_cmd(proc);
// 	child_exit = 0;
// 	while (true)
// 	{
// 		i = 0;
// 		while (i < proc->cmds_count)
// 		{
// 			if (proc->cmds[i]->error)
// 			{
// 				i++;
// 				continue ;
// 			}
// 			child_exit += child_has_exit(proc, i);
// 			i++;
// 		}
// 		if (child_exit == count_valid_child)
// 			break ;
// 	}
// }

void	exec_childs(t_proc *proc)
{
	int32_t	i;
	int32_t	count;

	i = 0;
	count = count_valid_cmd(proc);
	dup2(proc->f_out, STDOUT_FILENO);
	dup2(proc->f_in, STDIN_FILENO);
	close(proc->f_out);
	close(proc->f_in);
	while (i < proc->cmds_count)
	{
		if (!proc->cmds[i]->error)
		{
			if (count == 1)
				fork_single_child(proc, i);
			else if (i == 0)
				fork_first_child(proc, i);
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
	if (proc->command_found && execve(proc->cmds[i]->args[0],
			proc->cmds[i]->args, proc->envp) == -1)
	{
		write_msg(STDERR_FILENO, "Could not execve command: ");
		write_msg(STDERR_FILENO, proc->cmds[i]->cmd);
		write_msg(STDERR_FILENO, "\n");
		free_exit(EXIT_FAILURE);
	}
}

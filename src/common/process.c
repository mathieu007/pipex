/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 07:57:14 by mroy              #+#    #+#             */
/*   Updated: 2023/03/14 17:26:18 by mroy             ###   ########.fr       */
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

	i = 0;
	while (i < proc->cmds_count)
	{
		if (!proc->cmds[i]->error)
		{
			if (ft_strncmp(proc->cmds[i]->cmd, "sleep", 5) == 0)
				waitpid(proc->cmds[i]->pid, &status, 0);
			else
				waitpid(proc->cmds[i]->pid, &status, WNOHANG);
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
	if (execve(proc->cmds[i]->full_path_cmd,
				proc->cmds[i]->args,
				proc->envp) == -1)
	{
		write_msg(STDERR_FILENO, "Could not execve command: ");
		write_msg(STDERR_FILENO, proc->cmds[i]->cmd);
		write_msg(STDERR_FILENO, "\n");
		free_exit(EXIT_FAILURE);
	}
}

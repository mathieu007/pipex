/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 08:02:59 by math              #+#    #+#             */
/*   Updated: 2023/03/17 10:42:25 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_addr(char **addr)
{
	if (*addr)
	{
		free(*addr);
		*addr = NULL;
	}
}

void	close_fds(t_proc *proc, bool with_std_fd)
{
	int32_t	i;

	i = 0;
	if (proc->cmds)
	{
		while (proc->cmds[i])
		{
			if (proc->cmds[i]->file_in != -1)
				close(proc->cmds[i]->file_in);
			if (proc->cmds[i]->file_out != -1)
				close(proc->cmds[i]->file_out);
			i++;
		}
	}
	if (proc->f_in != -1)
		close(proc->f_in);
	if (proc->f_out != -1)
		close(proc->f_out);
	if (with_std_fd)
	{
		close(0);
		close(1);
		close(2);
	}
}

void	free_cmds(t_proc *proc)
{
	int32_t	i;

	i = 0;
	while (i < proc->cmds_count)
	{
		free_cmd(proc, i);
		i++;
	}
	free(proc->cmds);
	proc->cmds = NULL;
}

void	free_cmd(t_proc *proc, int32_t i)
{
	int32_t	i2;

	i2 = 0;
	if (proc->cmds[i] && proc->cmds[i]->args)
	{
		while (proc->cmds[i]->args[i2])
		{
			free_addr(&(proc->cmds[i]->args[i2]));
			i2++;
		}
		free(proc->cmds[i]->args);
		free(proc->cmds[i]->cmd);
		proc->cmds[i]->args = NULL;
	}
	free(proc->cmds[i]);
	proc->cmds[i] = NULL;
}

void	free_paths(t_proc *proc)
{
	int32_t	i;

	i = 0;
	if (proc->paths)
	{
		while (proc->paths[i])
		{
			free_addr(&(proc->paths[i]));
			i++;
		}
		free(proc->paths);
		proc->paths = NULL;
	}
}

void	free_all(void)
{
	t_proc	*proc;

	proc = get_proc();
	if (proc == NULL)
		return ;
	free_paths(proc);
	free_addr(&(proc->f_in_name));
	free_addr(&(proc->f_out_name));
	free_addr(&(proc->pwd));
	if (proc->cmds != NULL)
		free_cmds(proc);
	close_fds(proc, true);
}

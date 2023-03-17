/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 08:02:59 by math              #+#    #+#             */
/*   Updated: 2023/03/15 11:40:13 by mroy             ###   ########.fr       */
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
}

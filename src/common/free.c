/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 08:02:59 by math              #+#    #+#             */
/*   Updated: 2023/03/09 07:42:07 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_cmds(t_proc *proc)
{
	int32_t	i;
	int32_t	i2;

	i = 0;
	while (i < proc->cmds_count)
	{
		i2 = 0;
		if (proc->cmds[i] && proc->cmds[i]->args)
		{
			while (proc->cmds[i]->args[i2])
			{
				free(proc->cmds[i]->args[i2]);
				proc->cmds[i]->args[i2] = NULL;
				i2++;
			}
			free(proc->cmds[i]->args);
			proc->cmds[i]->args = NULL;
		}
		free(proc->cmds[i]);
		proc->cmds[i] = NULL;
		i++;
	}
	free(proc->cmds);
	proc->cmds = NULL;
}

void	free_paths(t_proc *proc)
{
	int32_t	i;

	i = 0;
	if (proc->paths)
	{
		while (proc->paths[i])
		{
			free(proc->paths[i]);
			proc->paths[i] = NULL;
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
	if (proc->f_in_name)
	{
		free(proc->f_in_name);
		proc->f_in_name = NULL;
	}
	if (proc->f_out_name)
	{
		free(proc->f_out_name);
		proc->f_out_name = NULL;
	}
	if (proc->cmds != NULL)
		free_cmds(proc);
}

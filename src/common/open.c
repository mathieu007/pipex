/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:40:18 by math              #+#    #+#             */
/*   Updated: 2023/03/16 10:36:26 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	open_temp_file(t_proc *proc)
{
	char	*temp;
	char	*name;

	write_msg(2, strerror(errno));
	write_msg(2, ": ");
	write_msg(2, proc->f_in_name);
	write_msg(2, "\n");
	temp = proc->f_in_name;
	name = ft_strchrlast(proc->f_in_name, '/');
	if (!name)
	{
		free(name);
		free_err_exit(EXIT_FAILURE);
	}
	proc->f_in_name = ft_strjoin(proc->pwd, name + 1);
	if (!proc->f_in_name)
		free_err_exit(EXIT_FAILURE);
	free(temp);
	proc->f_in = open(proc->f_in_name, O_RDONLY | O_CREAT | O_TRUNC, 0777);
	if (proc->f_in == -1)
		free_exit(EXIT_FAILURE);
	proc->waitpid = WNOHANG;
	proc->f_in_temp = true;
}

int32_t	open_files(t_proc *proc)
{
	int32_t	out_flags;

	proc->f_in_temp = false;
	out_flags = O_WRONLY | O_CREAT;
	if (!proc->here_doc)
	{
		out_flags |= O_TRUNC;
		proc->f_in = open(proc->f_in_name, O_RDONLY, 0777);
		if (proc->f_in == -1)
			open_temp_file(proc);
	}
	else
	{
		out_flags |= O_APPEND;
		proc->f_in = 0;
	}
	proc->f_out = open(proc->f_out_name, out_flags, 0644);
	if (proc->f_out == -1)
	{
		write_msg(2, strerror(errno));
		write_msg(2, proc->f_out_name);
		write_msg(2, "\n");
		free_exit(EXIT_FAILURE);
	}
	return (proc->f_out);
}

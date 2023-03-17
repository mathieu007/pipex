/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 08:03:11 by math              #+#    #+#             */
/*   Updated: 2023/03/16 09:18:53 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errno.h"
#include "pipex.h"

void	write_msg(int32_t stderror, char *msg)
{
	if (msg)
		write(stderror, msg, ft_strlen(msg));
}

void	*free_exit(int32_t exit_code)
{
	t_proc	*proc;

	proc = get_proc();
	if (proc->f_in)
	{
		if (proc->f_in_temp)
			unlink_fifo(get_proc()->f_in_name);
		close(proc->f_in);
	}
	if (proc->f_out)
		close(proc->f_out);
	free_all();
	exit(exit_code);
}

void	*free_err_exit(int32_t exit_code)
{
	t_proc	*proc;

	proc = get_proc();
	if (proc->f_in)
	{
		if (proc->f_in_temp)
			unlink_fifo(get_proc()->f_in_name);
		close(proc->f_in);
	}
	free_all();
	write_msg(STDERR_FILENO, strerror(errno));
	exit(exit_code);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 08:03:11 by math              #+#    #+#             */
/*   Updated: 2023/03/10 13:34:14 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errno.h"
#include "pipex.h"

void	write_msg(const char *msg, int32_t stderror, bool with_lf)
{
	if (msg != NULL)
	{
		write(stderror, msg, ft_strlen(msg));
		if (with_lf)
			write(stderror, "\n", 1);
	}
}

void	write_error(int32_t stderror, bool with_lf)
{
	if (errno)
	{
		write(stderror, strerror(errno), ft_strlen(strerror(errno)));
		if (with_lf)
			write(stderror, "\n", 1);
	}
}

void	error_exit(const char *msg, int32_t stderror, bool show_error_msg,
		int32_t exit_code)
{
	t_proc	*proc;

	proc = get_proc();
	free_all();
	if (proc->f_in)
	{
		close(proc->f_in);
		unlink_fifo(get_proc()->f_in_name);
	}
	if (proc->f_out)
	{
		close(proc->f_out);
		unlink_fifo(get_proc()->f_out_name);
	}
	if (msg)
		write_msg(msg, stderror, true);
	if (show_error_msg)
		write_error(stderror, true);
	exit(exit_code);
}

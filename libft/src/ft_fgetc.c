/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fgetc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:52:59 by mroy              #+#    #+#             */
/*   Updated: 2023/03/08 07:09:43 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_fgetc(t_file *stream)
{
	int	rval;

	if (!stream)
		return (-1);
	if (!stream->buf[stream->i])
	{
		stream->i = 0;
		rval = read(stream->fd, stream->buf, BUFFER_SIZE);
		if (rval <= 0)
		{
			stream->buf[0] = 0;
			return (-1);
		}
		stream->buf[rval] = 0;
	}
	return ((int)stream->buf[stream->i++]);
}

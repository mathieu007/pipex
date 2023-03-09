/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fopen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 08:05:20 by math              #+#    #+#             */
/*   Updated: 2023/03/08 07:09:43 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Initializes the stream associated with the file path.
/// @param path
/// @return
t_file	*ft_fopen(const char *path)
{
	t_file	*stream;

	stream = (t_file *)malloc(sizeof(t_file));
	if (!(stream))
		return (NULL);
	stream->fd = open(path, O_RDONLY);
	if (stream->fd == -1)
	{
		free(stream);
		return (NULL);
	}
	ft_bzero(stream->buf, sizeof(char) * (BUFFER_SIZE + 1));
	stream->i = 0;
	return (stream);
}

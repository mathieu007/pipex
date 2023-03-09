/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_temp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 07:00:54 by math              #+#    #+#             */
/*   Updated: 2023/02/27 21:48:45 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buff(int32_t fd, char **cur_buff, char *save)
{
	int32_t		bytes;
	static char	buff[TMP_BUFFER_SIZE + 1];

	if (fd < 0)
		return (NULL);
	bytes = read(fd, buff, TMP_BUFFER_SIZE);
	*cur_buff = &buff[0];
	if (bytes == 0 && *save != '\0')
	{
		*buff = '\0';
		*cur_buff = NULL;
		return (save);
	}
	else if (bytes == -1)
	{
		*buff = '\0';
		*save = '\0';
		*cur_buff = NULL;
		return (NULL);
	}
	buff[bytes] = '\0';
	return (ret_buff(fd, cur_buff, save));
}

char	*ret_buff(int32_t fd, char **cur_buff, char *save)
{
	char	*cur;

	cur = *cur_buff;
	while (*cur != '\0')
	{
		if (*cur == '\n')
		{
			*save++ = *cur++;
			*cur_buff = cur;
			*save = '\0';
			return (save);
		}
		*save++ = *cur++;
	}
	*cur_buff = cur;
	return (read_buff(fd, cur_buff, save));
}

char	*get_next_line_temp(int fd)
{
	static char	save[TMP_BUFFER_SIZE + 1];
	static char	*cur_buff;

	if (cur_buff == NULL)
	{
		*save = '\0';
		read_buff(fd, &cur_buff, &save[0]);
		return (save);
	}
	ret_buff(fd, &cur_buff, &save[0]);
	return (save);
}

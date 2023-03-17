/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 08:05:20 by math              #+#    #+#             */
/*   Updated: 2023/03/14 10:48:05 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free_line(char **line)
{
	if (line && *line)
	{
		free(*line);
		*line = NULL;
	}
}

static inline int32_t	get_copy_lenght(char *buffer)
{
	int32_t	copy_len;

	copy_len = 0;
	while (*buffer)
	{
		copy_len++;
		if (*buffer == '\n')
			break ;
		buffer++;
	}
	return (copy_len);
}

char	*resize_copy_line(char *buffer, char *line, int32_t *line_len)
{
	char	*temp;
	int32_t	copy_len;

	copy_len = get_copy_lenght(&buffer[0]);
	if (copy_len == 0)
		return (line);
	*line_len += copy_len;
	temp = line;
	line = malloc(*line_len + 1);
	if (!line)
		return (free_line(&temp), NULL);
	line[*line_len] = '\0';
	if (temp)
		ft_strcpy2(line, temp);
	ft_strlcpy2(&line[*line_len - copy_len], buffer, copy_len);
	ft_strcpy2(buffer, &buffer[copy_len]);
	free_line(&temp);
	return (line);
}

char	*get_next_line(int32_t fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int32_t		rd;
	int32_t		line_len;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	rd = 1;
	line_len = 0;
	line = NULL;
	while (rd)
	{
		if (*buffer)
			line = resize_copy_line(buffer, line, &line_len);
		if (line && line[line_len - 1] == '\n')
			return (line);
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
			return (*buffer = 0, free_line(&line), NULL);
		if (rd < BUFFER_SIZE)
			buffer[rd] = '\0';
		if (rd == 0)
			return (*buffer = 0, line);
	}
	return (*buffer = 0, free_line(&line), NULL);
}

// int	main(void)
// {
// 	int32_t	fd;
// 	char	*ret;

// 	fd = open("multiple_line_with_nl", O_RDWR);
// 	ret = get_next_line(fd);
// 	printf("line:%s", ret);
// 	free(ret);
// 	ret = get_next_line(fd);
// 	printf("line:%s", ret);
// 	free(ret);
// 	ret = get_next_line(fd);
// 	printf("line:%s", ret);
// 	free(ret);
// 	close(fd);
// }

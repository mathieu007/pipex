/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 07:52:27 by mroy              #+#    #+#             */
/*   Updated: 2023/03/02 13:57:19 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define TMP_BUFFER_SIZE 10000

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line_temp(int fd);
char	*read_buff(int32_t fd, char **cur_buff, char *save);
char	*ret_buff(int32_t fd, char **cur_buff, char *save);

#endif
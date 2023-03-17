/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:47:31 by mroy              #+#    #+#             */
/*   Updated: 2022/10/25 08:20:40 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*d_cpy;
	const char	*s_cpy;
	size_t		n;
	size_t		d_len;

	s_cpy = src;
	d_cpy = dst;
	n = dstsize;
	while (n-- != 0 && *d_cpy != '\0')
		d_cpy++;
	d_len = d_cpy - dst;
	n = dstsize - d_len;
	if (n == 0)
		return (d_len + ft_strlen(s_cpy));
	while (*s_cpy != '\0')
	{
		if (n != 1)
		{
			*d_cpy++ = *s_cpy;
			n--;
		}
		s_cpy++;
	}
	*d_cpy = '\0';
	return (d_len + (s_cpy - src));
}

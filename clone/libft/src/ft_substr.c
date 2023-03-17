/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:16:34 by mathieu           #+#    #+#             */
/*   Updated: 2022/12/09 10:33:45 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(char const *s, unsigned int start, size_t len)
{
	size_t	s_l;
	size_t	size;

	s_l = ft_strlen(s);
	if (start >= s_l)
		size = 1;
	else if (start + len <= s_l)
		size = len + 1;
	else
		size = s_l - start + 1;
	return (size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*mem;
	size_t	i;
	size_t	size;

	if (!s)
		return (0);
	size = ft_size(s, start, len);
	mem = (char *)malloc(sizeof(char) * size);
	if (!mem)
		return (NULL);
	i = 0;
	while (i < (size - 1) && s[i + start] != '\0')
	{
		mem[i] = s[i + start];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}

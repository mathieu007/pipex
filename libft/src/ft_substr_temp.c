/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_temp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:46:32 by mroy              #+#    #+#             */
/*   Updated: 2023/02/24 13:46:36 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

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

char	*ft_substr_temp(char const *s, unsigned int start, size_t len)
{
	char	*mem;
	size_t	i;
	size_t	size;

	if (!s)
		return (0);
	size = ft_size(s, start, len);
	mem = (char *)temp_pool(sizeof(char) * size);
	i = 0;
	while (i < (size - 1) && s[i + start] != '\0')
	{
		mem[i] = s[i + start];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}

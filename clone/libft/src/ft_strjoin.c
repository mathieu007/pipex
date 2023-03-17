/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:16:34 by mathieu           #+#    #+#             */
/*   Updated: 2022/10/28 15:29:13 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mem;
	size_t	s1_l;
	size_t	s2_l;

	s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	mem = (char *)malloc(sizeof(char) * (s1_l + s2_l + 1));
	if (!mem)
		return (NULL);
	ft_memcpy(mem, s1, s1_l);
	ft_memcpy(&mem[s1_l], s2, s2_l);
	mem[s1_l + s2_l] = '\0';
	return (mem);
}

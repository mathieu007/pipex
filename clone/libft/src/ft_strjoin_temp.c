/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_temp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:16:34 by mathieu           #+#    #+#             */
/*   Updated: 2023/02/27 22:24:33 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_temp(char const *s1, char const *s2)
{
	char	*mem;
	size_t	s1_l;
	size_t	s2_l;

	s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	mem = (char *)temp_pool(s1_l + s2_l + 1);
	ft_memcpy(mem, s1, s1_l);
	ft_memcpy(&mem[s1_l], s2, s2_l);
	mem[s1_l + s2_l] = '\0';
	return (mem);
}

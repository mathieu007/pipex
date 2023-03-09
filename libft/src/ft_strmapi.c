/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:16:34 by mathieu           #+#    #+#             */
/*   Updated: 2022/10/24 15:14:51 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mem;
	unsigned int	s_l;
	unsigned int	i;

	s_l = (unsigned int)ft_strlen(s);
	mem = (char *)malloc(sizeof(char) * (s_l + 1));
	if (!mem)
		return ((void *)0);
	i = 0;
	while (i < s_l)
	{
		mem[i] = (*f)(i, s[i]);
		i++;
	}
	mem[i] = '\0';
	return (mem);
}

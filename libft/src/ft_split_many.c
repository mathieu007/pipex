/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_many.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:03:57 by math              #+#    #+#             */
/*   Updated: 2023/02/28 19:51:11 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

char	**ft_split_many(char *s, char *separators)
{
	char	sep;
	int		i;
	int		s_i;

	sep = separators[0];
	separators++;
	s_i = 0;
	while (separators[s_i])
	{
		i = 0;
		while (s[i])
		{
			if (s[i] == separators[s_i])
				s[i] = sep;
			i++;
		}
		s_i++;
	}
	return (ft_split((const char *)s, sep));
}

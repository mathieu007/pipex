/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_many_temp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:03:57 by math              #+#    #+#             */
/*   Updated: 2023/02/08 10:55:02 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

char	**ft_split_many_temp(char *s, char *separators)
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
	return (ft_split_temp((const char *)s, sep));
}

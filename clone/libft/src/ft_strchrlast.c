/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:16:34 by mathieu           #+#    #+#             */
/*   Updated: 2023/03/13 12:08:43 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchrlast(const char *s, char c)
{
	int	i;

	i = ft_strlen(s) - 1;
	if (i < 0)
		return (NULL);
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i--;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:16:34 by mathieu           #+#    #+#             */
/*   Updated: 2022/10/19 08:29:43 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_streq(const char *s1, const char *compare)
{
	if (!s1 || !compare)
		return (false);
	while (*compare && *s1 && *s1 == *compare)
	{
		s1++;
		compare++;
	}
	if (*compare == '\0')
		return (true);
	return (false);
}

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

bool	ft_strstartwith(const char *s1, const char *start_with)
{
	if (!s1 || !start_with)
		return (false);
	while (*start_with && *s1 && *s1 == *start_with)
	{
		s1++;
		start_with++;
	}
	if (*start_with == '\0')
		return (true);
	return (false);
}

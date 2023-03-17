/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2022/09/18 20:16:34 by mathieu           #+#    #+#             */
/*   Updated: 2022/10/19 08:29:43 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	iswhitespace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (true);
	return (false);
}

long	ft_atoi_long(char *str)
{
	long	neg;
	long	n;

	neg = 1;
	n = 0;
	while (*str != '\0' && iswhitespace(*str) == 1)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (ft_isdigit(*str) == 1)
		n = (n * (long)10) + (long)(*str++ - 48);
	return (n * neg);
}

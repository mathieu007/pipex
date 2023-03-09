/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:57:53 by mroy              #+#    #+#             */
/*   Updated: 2022/10/26 15:56:33 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_length(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	if (nb < 10 && nb > -10)
		return (++len);
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		siz;
	long	num;
	char	*c_num;
	int		i;

	num = n;
	siz = num_length(num);
	i = 0;
	c_num = malloc(sizeof(char) * (siz + 1));
	if (!c_num)
		return (NULL);
	if (num < 0)
	{
		num *= -1;
		c_num[0] = '-';
		i = 1;
	}
	c_num[siz] = '\0';
	while (siz-- != i)
	{
		c_num[siz] = num % 10 + '0';
		num /= 10;
	}
	return (c_num);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:51:32 by mroy              #+#    #+#             */
/*   Updated: 2023/03/06 09:51:36 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src_c;
	char	*dest_c;
	size_t	i;

	src_c = (char *)src;
	dest_c = (char *)dst;
	i = 0;
	if (dst == NULL && src == NULL)
		return (dst);
	if (dest_c > src_c)
		while (len-- > 0)
			dest_c[len] = src_c[len];
	else
	{
		while (i < len)
		{
			dest_c[i] = src_c[i];
			i++;
		}
	}
	return (dst);
}

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

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	h_len;
	size_t	n_len;

	if (haystack == NULL)
		return (NULL);
	h_len = ft_strlen(haystack);
	n_len = ft_strlen(needle);
	i = 0;
	if (n_len > len)
		return (NULL);
	if (needle == (void *)0 || *needle == '\0')
		return ((char *)haystack);
	while (i + n_len <= len && i < h_len)
	{
		if (haystack[i] == needle[0] && ft_strncmp(&haystack[i], needle,
				n_len) == 0)
		{
			return ((char *)(&haystack[i]));
		}
		i++;
	}
	return (NULL);
}

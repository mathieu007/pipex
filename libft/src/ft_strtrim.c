/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:16:34 by mathieu           #+#    #+#             */
/*   Updated: 2022/10/26 10:42:36 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_matching_chars(char const *s1, char const *set)
{
	int	i;
	int	i2;
	int	match;

	i = 0;
	i2 = 0;
	match = 0;
	while (s1[i] != '\0')
	{
		i2 = 0;
		match = 0;
		while (set[i2] != '\0')
		{
			if (set[i2] == s1[i])
			{
				match = 1;
				break ;
			}
			i2++;
		}
		if (match != 1)
			return (i);
		i++;
	}
	return (i);
}

static int	reverse_count_matching_chars(char const *s1, char const *set)
{
	int	i;
	int	i2;
	int	match;

	i = ft_strlen(s1) - 1;
	i2 = 0;
	match = 0;
	while (i != 0)
	{
		i2 = 0;
		match = 0;
		while (set[i2] != '\0')
		{
			if (set[i2] == s1[i])
			{
				match = 1;
				break ;
			}
			i2++;
		}
		if (match != 1)
			return (ft_strlen(s1) - i - 1);
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*mem;
	size_t	start_count;
	size_t	end_count;
	size_t	s1_l;
	size_t	mem_l;

	s1_l = ft_strlen(s1);
	if (s1_l == 0)
	{
		mem = (char *)malloc(sizeof(char) * 1);
		if (!mem)
			return (NULL);
		mem[0] = '\0';
		return (mem);
	}
	start_count = count_matching_chars(s1, set);
	end_count = reverse_count_matching_chars(s1, set);
	mem_l = (s1_l - end_count - start_count);
	mem = (char *)malloc(sizeof(char) * (mem_l + 1));
	if (!mem)
		return (NULL);
	ft_memcpy(mem, &s1[start_count], mem_l);
	mem[mem_l] = '\0';
	return (mem);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_temp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:47:22 by mroy              #+#    #+#             */
/*   Updated: 2023/02/24 13:47:24 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	count;
	int	prev_pos;

	i = 0;
	count = 0;
	prev_pos = -1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			if (i - prev_pos > 1)
				count++;
			prev_pos = i;
		}
		i++;
	}
	if (i - prev_pos > 1)
		count++;
	return (count);
}

static char	**split_string(char **split, char const *s, char c)
{
	int	i;
	int	start_i;
	int	word_len;
	int	split_i;

	i = 0;
	start_i = 0;
	word_len = 0;
	split_i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
			i++;
		word_len = i - start_i;
		if (word_len > 0)
		{
			split[split_i++] = ft_substr_temp(s, start_i, word_len);
		}
		while (s[i] == c && s[i] != '\0')
			start_i = ++i;
	}
	split[split_i] = NULL;
	return (split);
}

char	**ft_split_temp(char const *s, char c)
{
	char	**split;
	int		word_len;

	word_len = count_word(s, c);
	split = (char **)temp_pool(sizeof(char **) * (word_len + 1));
	return (split_string(split, s, c));
}

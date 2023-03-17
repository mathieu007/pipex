/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:16:34 by mathieu           #+#    #+#             */
/*   Updated: 2023/03/09 10:05:05 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static void	*clear(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
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
			split[split_i] = ft_substr(s, start_i, word_len);
			if (split[split_i++] == NULL)
				return (clear(split));
		}
		while (s[i] == c && s[i] != '\0')
			start_i = ++i;
	}
	split[split_i] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		word_len;

	if (!s || *s == '\0')
		return (NULL);
	word_len = count_word(s, c);
	split = (char **)malloc(sizeof(char **) * (word_len + 1));
	if (!split)
		return (NULL);
	return (split_string(split, s, c));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_temp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 08:47:21 by math              #+#    #+#             */
/*   Updated: 2023/03/05 16:39:32 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*_replace(char *str, char *temp, char to_replace, char *replace_by)
{
	int32_t	i;
	int32_t	i_r;

	i = 0;
	while (*str)
	{
		if (*str == to_replace)
		{
			i_r = 0;
			while (replace_by[i_r])
			{
				temp[i] = replace_by[i_r];
				i_r++;
				i++;
			}
		}
		else
			temp[i++] = *str;
		str++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_replace_char_temp(char *str, char to_replace, char *replace_by)
{
	int32_t	char_count;
	int32_t	len;
	char	*temp;

	char_count = 0;
	len = ft_strlen(str);
	char_count = ft_count_char(str, to_replace);
	if (char_count == 0)
		return (str);
	temp = (char *)temp_pool(char_count + len + 1);
	return (_replace(str, temp, to_replace, replace_by));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+
        +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+
        +#+        */
/*                                                +#+#+#+#+#+
        +#+           */
/*   Created: 2022/11/14 20:38:39 by marvin            #+#    #+#             */
/*   Updated: 2022/11/14 20:38:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

/// @brief Find the item containing a max value.
/// the function pointer compare both item and return the greatest one.
int32_t	lst_filter_count(t_lst *lst, bool (*filter)(void *item1, void *values),
		void *values)
{
	int32_t	i;
	int32_t	count;

	i = 0;
	count = 0;
	while (i < lst->_count)
	{
		if (filter(lst_get(lst, i), values))
			count++;
		i++;
	}
	return (count);
}

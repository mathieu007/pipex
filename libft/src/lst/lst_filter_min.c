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

/// @brief Find the smallest item field
/// Then return the item.
/// comparer function should always return the smallest of the two item prev and
/// current
/// @param lst
/// @param start_index
/// @param field_offset
/// @param val
/// @return
void	*lst_filter_min(t_lst *lst, int32_t (*comparer)(t_lst *lst,
			int32_t index, int32_t prev))
{
	int32_t	i;
	int32_t	sm;

	sm = 0;
	i = 1;
	while (i < lst->_count)
	{
		sm = comparer(lst, i, sm);
		i++;
	}
	return (lst_get(lst, sm));
}

int32_t	lst_filter_min_index(t_lst *lst,
								int32_t (*comparer)(t_lst *lst, int32_t index,
										int32_t prev))
{
	int32_t	i;
	int32_t	sm;

	sm = 0;
	i = 1;
	while (i < lst->_count)
	{
		sm = comparer(lst, i, sm);
		i++;
	}
	return (sm);
}

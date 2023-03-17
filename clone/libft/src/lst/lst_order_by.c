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

/// @brief The comparer func must return the index of one of the smallest item.
/// it's the func that s hould define if it should be ordered by desc or asc.
/// make a copy of the list if you don<t want the list to be modified.
/// @param lst
/// @param start_index
/// @param field_offset
/// @param val
/// @return
t_lst	*lst_order_by(t_lst *lst, int32_t (*comparer)(t_lst *lst, int32_t index,
			int32_t prev))
{
	int32_t	i;
	int32_t	j;
	int32_t	swap_index;

	i = 0;
	j = i;
	while (i < lst->_count)
	{
		swap_index = i;
		j = i + 1;
		while (j < lst->_count)
		{
			swap_index = comparer(lst, j, swap_index);
			j++;
		}
		if (swap_index != i)
			lst_swap(lst, i, swap_index, 1);
		i++;
	}
	return (lst);
}

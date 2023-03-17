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

static void	_group_data(t_group_by *group_by_clause,
						t_lst *data_copy,
						bool (*comparer)(t_lst *lst, int32_t index,
								int32_t prev_index))
{
	int32_t	i;
	int32_t	j;
	t_lst	*group;

	i = 0;
	j = i;
	while (i < data_copy->_count)
	{
		j = i + 1;
		group = lst_new_temp(8, data_copy->_size);
		_lst_group_by_add_temp(group_by_clause, group);
		lst_add(group, (void *)lst_get(data_copy, i));
		while (j < data_copy->_count)
		{
			if (comparer(data_copy, j, i) && i + 1 != j)
			{
				i++;
				lst_swap(data_copy, i, j, 1);
				lst_add(group, (void *)lst_get(data_copy, i));
			}
			j++;
		}
		i++;
	}
}

/// @brief The comparer func is just a function that compare the current item.
/// with the previous one, if the current value is the same as the previous one,
/// then you should return true otherwise false.
/// @param lst
/// @param start_index
/// @param field_offset
/// @param val
/// @return
t_group_by	*lst_group_by(t_lst *lst, bool (*comparer)(t_lst *lst,
			int32_t index, int32_t prev_index))
{
	t_group_by	*group_by_clause;
	t_lst		*data_copy;

	data_copy = lst_copy_temp(lst);
	group_by_clause = _lst_group_by_new_temp(lst->_count / 5);
	_group_data(group_by_clause, data_copy, comparer);
	return (group_by_clause);
}

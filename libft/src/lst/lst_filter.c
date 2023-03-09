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

/// data will be returned in a temp lst pool.
/// if pointer returned by function pointer is NULL then item is not inserted
/// @param lst
/// @param start_index
/// @param field_offset
/// @param val
/// @return
t_lst	*lst_filter(t_lst *lst, bool (*match_item)(void *item, void *values),
		void *values)
{
	t_lst	*new_lst;
	int32_t	i;
	void	*item;

	i = 0;
	new_lst = lst_new_temp(lst->_count, lst->_size);
	while (i < lst->_count)
	{
		item = lst_get(lst, i);
		if (match_item(item, values))
			lst_add(new_lst, item);
		i++;
	}
	return (new_lst);
}

t_lst	*lst_filter_is_any_of(t_lst *lst, bool (*match_item)(t_lst *lst,
			int32_t index, void *values, int32_t count), void *values,
		int32_t count)
{
	t_lst	*new_lst;
	int32_t	i;

	i = 0;
	new_lst = lst_new_temp(lst->_count, lst->_size);
	if (!new_lst)
		return (NULL);
	while (i < lst->_count)
	{
		if (match_item(lst, i, values, count))
			lst_add(new_lst, lst_get(lst, i));
		i++;
	}
	return (new_lst);
}

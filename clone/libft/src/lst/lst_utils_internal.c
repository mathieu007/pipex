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

int32_t	_lst_start_i(t_lst *lst)
{
	return (lst->_offset * lst->_size);
}

int32_t	_lst_end_i(t_lst *lst)
{
	return ((lst->_offset * lst->_size) + (lst->_count * lst->_size));
}

t_lst	*_internal_resize_temp(t_lst *lst, int32_t elem_count_to_add)
{
	uint8_t	*old_data;
	int32_t	new_length;
	int32_t	new_offset;

	new_length = lst->_capacity * 3;
	old_data = lst->data;
	while (new_length <= lst->_count + elem_count_to_add)
		new_length *= 3;
	lst->data = temp_pool(new_length * lst->_size);
	if (!lst->data)
		return (NULL);
	new_offset = (new_length / 2) - ((lst->_count + elem_count_to_add) / 2);
	ft_memcpy(&lst->data[new_offset * lst->_size], &old_data[lst->_offset
		* lst->_size], lst->_count * lst->_size);
	lst->_capacity = new_length;
	lst->_offset = new_offset;
	free(old_data);
	return (lst);
}

t_lst	*_internal_resize(t_lst *lst, int32_t elem_count_to_add)
{
	uint8_t	*old_data;
	int32_t	new_length;
	int32_t	new_offset;
	void	*data;

	data = lst->data;
	new_length = lst->_capacity * 3;
	old_data = lst_addr(lst, 0);
	while (new_length <= lst->_count + elem_count_to_add)
		new_length *= 3;
	lst->data = lst->_alloc(lst, new_length * lst->_size);
	if (!lst->data)
		return (NULL);
	lst->_capacity = new_length;
	new_offset = (new_length / 2) - ((lst->_count + elem_count_to_add) / 2);
	lst->_offset = new_offset;
	ft_memmove(lst_addr(lst, 0), old_data, lst->_count * lst->_size);
	lst->_capacity = new_length;
	lst->_free_data(data);
	return (lst);
}

/// @brief use this function only if capacity is not big enough.
/// this function will resize the data and leave an empty space of:
/// elem_count at index.
/// @param lst
/// @param index
/// @param elem_count_to_insert
/// @return
t_lst	*_internal_resize_insert(t_lst *lst, int32_t index, int32_t elem_count)
{
	uint8_t	*old_data;
	int32_t	new_length;
	int32_t	new_offset;

	new_length = lst->_capacity * 3;
	old_data = &(lst->data)[lst->_offset * lst->_size];
	while (new_length <= lst->_count + elem_count)
		new_length *= 3;
	lst->_capacity = new_length;
	lst->data = lst->_alloc(lst, new_length * lst->_size);
	if (!lst->data)
		return (NULL);
	new_offset = (new_length / 2) - ((lst->_count + elem_count) / 2)
		+ elem_count;
	lst->_offset = new_offset;
	if (index > 0)
	{
		ft_memmove(lst_addr(lst, new_offset), old_data, index * lst->_size);
	}
	ft_memmove(lst_addr(lst, index + elem_count),
		&old_data[index * lst->_size],
		(lst->_count - index) * lst->_size);
	lst->_free_data((void *)old_data);
	return (lst);
}

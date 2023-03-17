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

t_lst	*lst_copy_data(t_lst *src, t_lst *dst)
{
	if (!src || !dst)
		return (NULL);
	dst->_offset = dst->_capacity / 3;
	dst->_count = src->_count;
	ft_memcpy(&dst->data[dst->_offset * dst->_size],
		&src->data[src->_offset * src->_size],
		src->_count * src->_size);
	return (dst);
}

t_lst	*lst_copy(t_lst *lst)
{
	t_lst	*new_lst;

	if (!lst)
		return (NULL);
	new_lst = lst_new(lst->_count, lst->_size);
	if (!new_lst)
		return (NULL);
	ft_memcpy(&new_lst->data[new_lst->_offset * new_lst->_size],
		&lst->data[lst->_offset * lst->_size],
		lst->_count * lst->_size);
	new_lst->_count = lst->_count;
	return (new_lst);
}

t_lst	*lst_copy_fixed(t_lst *lst)
{
	t_lst	*new_lst;

	if (!lst)
		return (NULL);
	new_lst = lst_new_fixed(lst->_count, lst->_size);
	if (!new_lst)
		return (NULL);
	ft_memcpy(&new_lst->data[new_lst->_offset * new_lst->_size],
		&lst->data[lst->_offset * lst->_size],
		lst->_count * lst->_size);
	new_lst->_count = lst->_count;
	return (new_lst);
}

t_lst	*lst_copy_temp(t_lst *lst)
{
	t_lst	*new_lst;

	if (!lst)
		return (NULL);
	new_lst = lst_new_temp(lst->_count, lst->_size);
	if (!new_lst)
		return (NULL);
	ft_memcpy(&new_lst->data[new_lst->_offset * new_lst->_size],
		&lst->data[lst->_offset * lst->_size],
		lst->_count * lst->_size);
	new_lst->_count = lst->_count;
	return (new_lst);
}

/// @brief data should be 3 time of the ecpected actual size
/// @brief data_elem_count should be 3 time the actual elem count expected
/// @param lst
/// @param data
/// @return
t_lst	*lst_copy_static(t_lst *lst, void *data, int32_t max_capacity)
{
	t_lst	*new_lst;

	if (!lst)
		return (NULL);
	new_lst = lst_new_static(data, max_capacity, lst->_size);
	if (!new_lst)
		return (NULL);
	ft_memcpy(&new_lst->data[new_lst->_offset * new_lst->_size],
		&lst->data[lst->_offset * lst->_size],
		lst->_count * lst->_size);
	new_lst->_count = lst->_count;
	return (new_lst);
}

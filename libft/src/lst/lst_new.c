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

t_lst	*lst_new(int32_t array_elem_count, int32_t size_of_elem)
{
	t_lst	*lst;

	lst = malloc(sizeof(t_lst));
	if (!lst)
		return (NULL);
	lst->_offset = array_elem_count;
	array_elem_count *= 3;
	lst->_alloc = &_malloc;
	lst->_free = &_free_malloc;
	lst->_free_data = &_free_data_malloc;
	lst->data = lst->_alloc(lst, array_elem_count * size_of_elem);
	if (!lst->data)
		return (free(lst), NULL);
	lst->_count = 0;
	lst->_is_static = false;
	lst->_size = size_of_elem;
	lst->_capacity = array_elem_count;
	return (lst);
}

/// @brief you will pass the data buffer yourself.
/// WARNING this list cannot be resized if you you execute a 
///function that execute a _resize
/// the app will crash
/// static data[size]: size should be more than necessary at 
/// least 3 time the expected size
/// WARNING size_of_elem should be the size of the struct itself
/// not the pointer size.
/// @param array_size
/// @param size_of_elem
/// @return
t_lst	*lst_new_static(void *data, int32_t max_capacity, size_t size_of_elem)
{
	t_lst	*lst;

	lst = (t_lst *)data;
	lst->_offset = max_capacity / 3;
	lst->data = &((uint8_t *)data)[sizeof(t_lst)];
	lst->_alloc = &_alloc_static;
	lst->_free = &_free_static;
	lst->_free_data = &_free_data_static;
	lst->_size = size_of_elem;
	lst->_is_static = true;
	lst->_capacity = max_capacity;
	return (lst);
}

/// @brief WARNING: if you use the memory pool the array will be
/// twice the size expected.
/// no resize ever possible.
/// use this for temporary lst which will be deleted at the end of a function.
/// @param array_size
/// @param size_of_elem
/// @return
t_lst	*lst_new_temp(int32_t array_elem_count, int32_t size_of_elem)
{
	t_lst	*lst;

	lst = (t_lst *)temp_pool(sizeof(t_lst));
	lst->_offset = array_elem_count;
	array_elem_count *= 3;
	lst->_alloc = &_alloc_temp;
	lst->_free = &_free_temp;
	lst->_free_data = &_free_data_temp;
	lst->data = lst->_alloc(lst, array_elem_count * size_of_elem);
	lst->_count = 0;
	lst->_is_static = false;
	lst->_size = size_of_elem;
	lst->_capacity = array_elem_count;
	return (lst);
}

/// @brief WARNING: if you use the memory pool the array will be 
/// twice the size expected.
/// no resize ever possible.
/// use this for lst which will use the fixed pool of memory.
/// unexpected result if not enough memory the pool.
t_lst	*lst_new_fixed(int32_t array_elem_count, int32_t size_of_elem)
{
	t_lst	*lst;

	lst = (t_lst *)mem_pool(sizeof(t_lst));
	lst->_offset = array_elem_count;
	array_elem_count *= 3;
	lst->_alloc = &_alloc_fixed;
	lst->_free = &_free_fixed;
	lst->_free_data = &_free_data_fixed;
	lst->data = lst->_alloc(lst, array_elem_count * size_of_elem);
	lst->_count = 0;
	lst->_size = size_of_elem;
	lst->_is_static = true;
	lst->_capacity = array_elem_count;
	return (lst);
}

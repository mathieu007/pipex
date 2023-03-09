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

t_lst	*lst_rotate_left(t_lst *lst, int32_t elem_count)
{
	int32_t	new_offset;

	if (!lst)
		return (NULL);
	if (lst->_capacity <= lst->_count + (elem_count * 2) + 10)
		_internal_resize(lst, elem_count);
	new_offset = lst->_offset + elem_count;
	if (lst->_count + lst->_offset + elem_count >= lst->_capacity)
	{
		new_offset = _lst_offset_mid(lst, -elem_count);
		ft_memmove(_lst_addr_offset(lst, new_offset), lst_addr(lst, 0),
			lst->_count * lst->_size);
		lst->_offset = new_offset;
		new_offset += 1;
	}
	ft_memmove(lst_addr(lst, lst->_count), lst_addr(lst, 0), elem_count
		* lst->_size);
	lst->_offset = new_offset;
	return (lst);
}

t_lst	*lst_rotate_right(t_lst *lst, int32_t elem_count)
{
	int32_t	new_offset;

	if (!lst)
		return (NULL);
	if (lst->_capacity <= lst->_count + (elem_count * 2) + 10)
		_internal_resize(lst, elem_count);
	new_offset = lst->_offset - elem_count;
	if (new_offset < 0)
	{
		new_offset = _lst_offset_mid(lst, elem_count);
		ft_memmove(_lst_addr_offset(lst, new_offset), lst_addr(lst, 0),
			lst->_count * lst->_size);
		lst->_offset = new_offset - elem_count;
		new_offset -= 1;
	}
	ft_memmove(lst_addr(lst, -elem_count), lst_addr(lst, lst->_count
			- elem_count), elem_count * lst->_size);
	lst->_offset = new_offset;
	return (lst);
}

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

t_lst	*lst_insert(t_lst *lst, int32_t index, void *item)
{
	if (!lst)
		return (NULL);
	if (lst->_capacity <= lst->_count + 10)
		_internal_resize_insert(lst, index, 1);
	else if (index == 0 && lst->_offset != 0)
		lst->_offset--;
	else if (index < lst->_count / 2 && lst->_offset != 0)
	{
		ft_memmove(lst_addr(lst, -1), lst_addr(lst, 0), index * lst->_size);
		lst->_offset--;
	}
	else if (index > lst->_count / 2 && lst->_count + lst->_offset
		+ 1 < lst->_capacity)
		ft_memmove(lst_addr(lst, index + 1), lst_addr(lst, index), (lst->_count
				- index) * lst->_size);
	*lst_addr_ptr(lst, index) = item;
	lst->_count++;
	return (lst);
}

t_lst	*lst_insert_int(t_lst *lst, int32_t index, int32_t item)
{
	if (!lst)
		return (NULL);
	if (lst->_capacity <= lst->_count + 10)
		_internal_resize_insert(lst, index, 1);
	else if (index == 0 && lst->_offset != 0)
		lst->_offset--;
	else if (index < lst->_count / 2 && lst->_offset != 0)
	{
		ft_memmove(lst_addr(lst, -1), lst_addr(lst, 0), index * lst->_size);
		lst->_offset--;
	}
	else if (index > lst->_count / 2 && lst->_count + lst->_offset
		+ 1 < lst->_capacity)
		ft_memmove(lst_addr(lst, index + 1), lst_addr(lst, index), (lst->_count
				- index) * lst->_size);
	*lst_addr_int_ptr(lst, index) = item;
	lst->_count++;
	return (lst);
}

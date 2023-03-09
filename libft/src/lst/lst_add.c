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

t_lst	*lst_add(t_lst *lst, void *value)
{
	if (!lst)
		return (NULL);
	if (lst->_capacity <= lst->_count + 10)
		_internal_resize(lst, 1);
	else if (lst->_offset + lst->_count + 1 >= lst->_capacity)
	{
		ft_memmove(_lst_addr_mid(lst, -1), lst_addr(lst, 0), lst->_count
			* lst->_size);
		lst->_offset = _lst_offset_mid(lst, -1);
	}
	*lst_addr_ptr(lst, lst->_count) = value;
	lst->_count++;
	return (lst);
}

t_lst	*lst_add_int(t_lst *lst, int32_t value)
{
	int32_t	*lst_data;

	if (!lst)
		return (NULL);
	if (lst->_capacity <= lst->_count + 10)
		_internal_resize(lst, 1);
	if (lst->_capacity <= lst->_count + 10 && lst->_is_static)
		_internal_resize(lst, 1);
	else if (lst->_offset + lst->_count + 1 >= lst->_capacity)
	{
		ft_memmove(_lst_addr_mid(lst, -1), lst_addr(lst, 0), lst->_count
			* lst->_size);
		lst->_offset = _lst_offset_mid(lst, -1);
	}
	lst_data = lst_addr_int_ptr(lst, lst->_count);
	*lst_data = value;
	lst->_count++;
	return (lst);
}

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

/// @brief the full alloc sized if _is_static : (_capacity * _size)
///	+ sizeof(t_lst)
/// or the (_capacity * _size) if not static
/// @param lst
/// @return
int32_t	lst_get_alloc_size(t_lst *lst)
{
	if (lst->_is_static)
		return ((lst->_capacity * lst->_size) + sizeof(t_lst));
	else
		return ((lst->_capacity * lst->_size));
}

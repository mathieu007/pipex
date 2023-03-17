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

/// @brief get the internal array of the list.
/// WARNING never modify the array, it's a readonly array.
/// @param lst
/// @return
const void	*lst_get_array(t_lst *lst)
{
	if (!lst)
		return (NULL);
	return ((void *)&lst->data[lst->_offset * lst->_size]);
}

/// @brief get the internal array of the list.
/// WARNING never modify the array, it's a readonly array.
/// @param lst
/// @return
const int32_t	*lst_get_int_array(t_lst *lst)
{
	if (!lst)
		return (NULL);
	return ((int32_t *)&lst->data[lst->_offset * lst->_size]);
}

void	*lst_free_to_array(t_lst *lst)
{
	uint8_t	*arr;

	if (!lst)
		return (NULL);
	arr = malloc(lst->_count * lst->_size);
	if (!arr)
		return (NULL);
	ft_memcpy(arr, &lst->data[lst->_offset * lst->_size], lst->_count
		* lst->_size);
	lst_free(lst);
	return ((void *)arr);
}

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

void	*lst_to_array(t_lst *lst)
{
	uint8_t	*arr;

	if (!lst)
		return (NULL);
	arr = malloc(lst->_count * lst->_size);
	if (!arr)
		return (NULL);
	ft_memcpy(arr, &lst->data[lst->_offset * lst->_size], lst->_count
		* lst->_size);
	return ((void *)arr);
}

/// @brief from memory pool make sure enought memory available
/// @param lst
/// @return
void	*lst_to_array_fixed(t_lst *lst)
{
	uint8_t	*arr;

	if (!lst)
		return (NULL);
	arr = mem_pool(lst->_count * lst->_size);
	ft_memcpy(arr, &lst->data[lst->_offset * lst->_size], lst->_count
		* lst->_size);
	return ((void *)arr);
}

/// @brief temp data only
/// @param lst
/// @return
int32_t	*lst_to_int_array_temp(t_lst *lst)
{
	uint8_t	*arr;

	if (!lst)
		return (NULL);
	arr = temp_pool(lst->_count * lst->_size);
	ft_memcpy(arr, &lst->data[lst->_offset * lst->_size], lst->_count
		* lst->_size);
	return ((int32_t *)arr);
}

/// @brief temp data only
/// @param lst
/// @return
void	*lst_to_array_temp(t_lst *lst)
{
	uint8_t	*arr;

	if (!lst)
		return (NULL);
	arr = temp_pool(lst->_count * lst->_size);
	ft_memcpy(arr, &lst->data[lst->_offset * lst->_size], lst->_count
		* lst->_size);
	return ((void *)arr);
}

/// @brief temp data only
/// @param lst
/// @return
void	*lst_to_array_static(t_lst *lst, void *dst)
{
	if (!lst)
		return (NULL);
	ft_memcpy(dst, &lst->data[lst->_offset * lst->_size], lst->_count
		* lst->_size);
	return ((void *)dst);
}

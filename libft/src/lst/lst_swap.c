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

/// @brief WARNING,  the second index should be the biggest one.
/// @param lst
/// @param index
/// @param index2
/// @param elem_count
void	lst_swap(t_lst *lst, int32_t index, int32_t index2, int32_t elem_count)
{
	int32_t	i;
	int32_t	i2;
	int32_t	max;
	int8_t	temp;

	if (index2 == index)
		return ;
	i = (index + lst->_offset) * lst->_size;
	i2 = (index2 + lst->_offset) * lst->_size;
	max = i2 + (elem_count * lst->_size);
	while (i2 < max)
	{
		temp = lst->data[i];
		lst->data[i] = lst->data[i2];
		lst->data[i2] = temp;
		i++;
		i2++;
	}
}

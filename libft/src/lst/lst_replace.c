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

t_lst	*lst_replace(t_lst *lst, int32_t index, void *ptr)
{
	uint8_t	*data;
	int32_t	i;
	uint8_t	*val;

	val = (uint8_t *)ptr;
	data = &lst->data[(lst->_count + lst->_offset - 1) * lst->_size];
	i = (index + lst->_offset) * lst->_size;
	while (i < lst->_size)
	{
		data[i] = *val++;
		i++;
	}
	return (lst);
}

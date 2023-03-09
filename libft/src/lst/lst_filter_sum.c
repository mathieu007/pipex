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

/// @brief Find the smallest item field
/// Then return the item.
/// @param lst
/// @param start_index
/// @param field_offset
/// @param val
/// @return
int64_t	lst_filter_sum(t_lst *lst, int64_t (*select)(t_lst *lst, int32_t index))
{
	int32_t	i;
	int64_t	sum;

	i = 0;
	sum = 0;
	while (i < lst->_count)
	{
		sum += select(lst, i);
		i++;
	}
	return (sum);
}

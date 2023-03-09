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

/// @brief an array of bool where the value is the index. 
/// useful to check if number is in the array,
///	WARNING max number should be small.
/// @param lst
/// @return
bool	*lst_int_to_bool_array(t_lst *lst, int32_t len, bool reverse)
{
	bool	*arr;
	int32_t	i;
	bool	val;
	bool	def;

	val = true;
	def = false;
	if (!lst)
		return (NULL);
	arr = (bool *)temp_pool(lst->_count * sizeof(bool));
	if (reverse)
	{
		val = false;
		def = true;
	}
	i = 0;
	while (i < len)
		arr[i++] = def;
	while (i < lst->_count)
		arr[lst_get_int(lst, i++)] = val;
	return (arr);
}

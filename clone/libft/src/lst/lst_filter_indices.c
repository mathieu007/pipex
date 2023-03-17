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

/// @brief the list returned is a list of indices that match the conditions
/// @param lst
/// @param match_item
/// @param values
/// @return
t_lst	*lst_filter_indices(t_lst *lst, bool (*match_item)(void *item,
			void *values), void *values)
{
	t_lst	*new_lst;
	int32_t	i;
	void	*item;

	i = 0;
	new_lst = lst_new_temp(lst->_count, lst->_size);
	while (i < lst->_count)
	{
		item = lst_get(lst, i);
		if (match_item(item, values))
			lst_add_int(new_lst, i);
		i++;
	}
	return (new_lst);
}

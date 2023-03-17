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

t_group_by	*_lst_group_by_new_temp(int32_t group_count)
{
	t_group_by	*group;

	group = (t_group_by *)group_by_clause_pool();
	group_count *= 2;
	group->_array_length = group_count;
	group->data = group_by_data_pool(group_count);
	group->_group_count = 0;
	return (group);
}

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

t_group_by	*_internal_group_by_resize_temp(t_group_by *grp,
											int32_t group_count_to_add)
{
	t_lst	**old_data;
	int32_t	new_length;

	new_length = grp->_array_length * 2;
	old_data = grp->data;
	while (new_length <= grp->_group_count + group_count_to_add)
		new_length *= 2;
	grp->data = group_by_data_pool(new_length * sizeof(t_lst *));
	ft_memcpy(grp->data,
		old_data,
		grp->_group_count * sizeof(t_lst *));
	grp->_array_length = new_length;
	grp->_group_count = grp->_group_count + group_count_to_add;
	return (grp);
}

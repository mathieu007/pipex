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

t_group_by	*_lst_group_by_add_temp(t_group_by *grp, t_lst *lst)
{
	if (!grp)
		return (NULL);
	if (grp->_array_length <= grp->_group_count + 1)
		_internal_group_by_resize_temp(grp, 1);
	grp->data[grp->_group_count] = lst;
	return (grp);
}

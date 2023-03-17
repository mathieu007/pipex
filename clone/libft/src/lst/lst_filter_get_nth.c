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

void	*lst_filter_get_nth(t_lst *lst, bool (*conditions)(t_lst *lst,
			int32_t index, void *values), void *values, int32_t nth_item)
{
	int32_t	i;
	int32_t	count;

	i = 0;
	count = 0;
	while (i < lst->_count)
	{
		if (conditions(lst, i, values))
			count++;
		if (nth_item == count)
			return (lst_get(lst, i));
		i++;
	}
	return ((void *)0);
}

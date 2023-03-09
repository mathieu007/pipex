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

void	*lst_filter_last(t_lst *lst, bool (*conditions)(t_lst *lst,
			int32_t index, void *values), void *values)
{
	int32_t	i;

	i = lst->_count - 1;
	while (i >= 0)
	{
		if (conditions(lst, i, values))
			return (lst_get(lst, i));
		i--;
	}
	return ((void *)0);
}

int32_t	lst_filter_last_index_of(t_lst *lst, bool (*conditions)(void *item,
			void *values), void *values)
{
	int32_t	i;

	i = lst->_count - 1;
	while (i >= 0)
	{
		if (conditions(lst_get(lst, i), values))
			return (i);
		i--;
	}
	return (-1);
}

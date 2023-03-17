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

int32_t	lst_filter_index_of_start_at(
	t_lst *lst, bool (*conditions)(t_lst *lst, int32_t index, void *values),
		int32_t start_index, void *values)
{
	int32_t	i;

	i = start_index;
	while (i < lst->_count)
	{
		if (conditions(lst, i, values))
			return (i);
		i++;
	}
	return (-1);
}

int32_t	lst_filter_index_of(t_lst *lst, bool (*conds)(void *item, void *values),
		void *values)
{
	int32_t	i;

	i = 0;
	while (i < lst->_count)
	{
		if (conds(lst_get(lst, i), values))
			return (i);
		i++;
	}
	return (-1);
}

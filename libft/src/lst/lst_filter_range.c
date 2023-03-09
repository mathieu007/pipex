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

/// data will be returned in a temp lst pool.
/// if pointer returned by function pointer is NULL then item is not inserted
/// @param lst
/// @param start_index
/// @param field_offset
/// @param val
/// @return
t_lst	*lst_filter_range(t_lst *lst, int32_t start_index, int32_t count)
{
	t_lst	*new_lst;
	int32_t	i;

	i = start_index;
	new_lst = lst_new_temp(count, lst->_size);
	count += start_index;
	while (i < lst->_count && i < count)
	{
		lst_add(new_lst, (void *)lst_get(lst, i));
		i++;
	}
	return (new_lst);
}

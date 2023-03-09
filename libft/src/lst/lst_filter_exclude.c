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

/// @brief
/// @param lst
/// @param exclude_indices
/// @return
t_lst	*lst_filter_exclude(t_lst *lst, t_lst *exclude_indices)
{
	t_lst	*new_lst;
	int32_t	i;
	bool	*exclude;

	exclude = lst_int_to_bool_array(exclude_indices, exclude_indices->_count,
			false);
	new_lst = lst_new_temp(lst->_count, lst->_size);
	if (!new_lst)
		return (NULL);
	i = 0;
	while (i < lst->_count)
	{
		if (!exclude[i])
			lst_add(new_lst, lst_get(lst, i++));
	}
	return (new_lst);
}

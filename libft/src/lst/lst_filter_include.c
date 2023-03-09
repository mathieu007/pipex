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
t_lst	*lst_filter_include(t_lst *lst, t_lst *include_indices)
{
	t_lst	*new_lst;
	int32_t	i;

	new_lst = lst_new_temp(include_indices->_count, include_indices->_size);
	if (!new_lst)
		return (NULL);
	i = 0;
	while (i < include_indices->_count)
	{
		lst_add(new_lst, lst_get(lst, lst_get_int(include_indices, i)));
		i++;
	}
	return (new_lst);
}

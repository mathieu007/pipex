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

t_lst	*lst_select(t_lst *lst,
					void *(*select)(void *item),
					size_t size_of_elem)
{
	t_lst	*new_lst;
	int32_t	i;

	new_lst = lst_new_temp(lst->_count, size_of_elem);
	i = 0;
	while (i < lst->_count)
	{
		lst_add(new_lst, select(lst_get(lst, i)));
		i++;
	}
	return (new_lst);
}

t_lst	*lst_select_int(t_lst *lst, int32_t (*select)(void *item))
{
	t_lst	*new_lst;
	int32_t	i;

	new_lst = lst_new_temp(lst->_count, sizeof(int));
	i = 0;
	while (i < lst->_count)
	{
		lst_add_int(new_lst, select(lst_get(lst, i)));
		i++;
	}
	return (new_lst);
}

int32_t	*lst_sel_int_to_array_fixed(t_lst *lst,
									int32_t (*select)(t_lst *lst,
														int32_t index))
{
	int32_t	*new_lst;
	int32_t	i;

	new_lst = (int32_t *)temp_pool(lst->_count * sizeof(int32_t));
	i = 0;
	while (i < lst->_count)
	{
		new_lst[i] = select(lst, i);
		i++;
	}
	return (new_lst);
}

int32_t	*lst_sel_int_to_array_temp(t_lst *lst,
									int32_t (*select)(t_lst *lst,
														int32_t index))
{
	int32_t	*new_lst;
	int32_t	i;

	new_lst = (int32_t *)temp_pool(lst->_count * sizeof(int32_t));
	i = 0;
	while (i < lst->_count)
	{
		new_lst[i] = select(lst, i);
		i++;
	}
	return (new_lst);
}

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

t_lst	*lst_reverse_select(t_lst *lst,
							void *(*select)(t_lst *lst, int32_t index))
{
	t_lst	*new_lst;
	int32_t	i;

	new_lst = lst_new_temp(lst->_count, sizeof(int32_t));
	i = lst->_count - 1;
	while (i >= 0)
	{
		lst_add(new_lst, select(lst, i));
		i--;
	}
	return (new_lst);
}

int32_t	*lst_reverse_select_int(t_lst *lst,
								int32_t (*select)(t_lst *lst,
													int32_t index))
{
	int32_t	*new_lst;
	int32_t	i;
	int32_t	j;

	new_lst = (int32_t *)temp_pool(lst->_count * sizeof(int32_t));
	i = lst->_count - 1;
	j = 0;
	while (i >= 0)
	{
		new_lst[j] = select(lst, i);
		i--;
		j++;
	}
	return (new_lst);
}

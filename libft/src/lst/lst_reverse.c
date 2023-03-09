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

t_lst	*lst_rev_to_lst_fixed(t_lst *lst)
{
	t_lst	*new_lst;
	int32_t	i;

	new_lst = lst_new_fixed(lst->_count, sizeof(void *));
	i = lst->_count - 1;
	while (i >= 0)
	{
		lst_add(new_lst, lst_get(lst, i));
		i--;
	}
	return (new_lst);
}

t_lst	*lst_reverse(t_lst *lst)
{
	t_lst	*new_lst;
	int32_t	i;

	new_lst = lst_new_temp(lst->_count, sizeof(void *));
	i = lst->_count - 1;
	while (i >= 0)
	{
		lst_add(new_lst, lst_get(lst, i));
		i--;
	}
	return (new_lst);
}

t_lst	*lst_reverse_int(t_lst *lst)
{
	t_lst	*new_lst;
	int32_t	i;

	new_lst = lst_new_temp(lst->_count, sizeof(int));
	i = lst->_count - 1;
	while (i >= 0)
	{
		lst_add_int(new_lst, lst_get_int(lst, i));
		i--;
	}
	return (new_lst);
}

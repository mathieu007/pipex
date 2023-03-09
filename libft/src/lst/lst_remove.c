/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+
        +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+
        +#+        */
/*                                                +#+#+#+#+#+
        +#+           */
/*   Created: 2022/12/12 09:25:16 by mroy              #+#    #+#             */
/*   Updated: 2022/12/12 09:25:16 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_lst	*lst_remove_at(t_lst *lst, int32_t index)
{
	if (!lst)
		return (NULL);
	if (index == 0)
		lst->_offset++;
	else
	{
		ft_memmove(&lst->data[(index + lst->_offset) * lst->_size],
			&(lst->data)[((lst->_offset + index + 1) * lst->_size)],
			(lst->_count - index - 1) * lst->_size);
	}
	lst->_count--;
	return (lst);
}

t_lst	*lst_remove_at_end(t_lst *lst, int32_t count)
{
	if (!lst)
		return (NULL);
	lst->_count -= count;
	return (lst);
}

t_lst	*lst_remove_last(t_lst *lst)
{
	if (!lst)
		return (NULL);
	lst->_count--;
	return (lst);
}

t_lst	*lst_remove_first(t_lst *lst)
{
	if (!lst)
		return (NULL);
	lst->_offset++;
	lst->_count--;
	return (lst);
}

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

/// @brief Find the item containing a max value.
/// the function pointer compare both item and return the greatest one.
void	*lst_filter_max(t_lst *lst, void *(*comparer)(void *item1, void *item2))
{
	int32_t	i;
	void	*gr_item;

	gr_item = lst_get(lst, 0);
	i = 1;
	while (i < lst->_count)
	{
		gr_item = comparer(gr_item, lst_get(lst, i));
		i++;
	}
	return (gr_item);
}

/// @brief Find the item containing a max value.
/// the comparer function return the largest item.
int32_t	lst_filter_max_index(t_lst *lst, void *(*comparer)(void *first,
			void *second))
{
	int32_t	i;
	void	*gr;
	void	*gr2;
	int32_t	gr_i;

	gr_i = 0;
	i = 1;
	if (lst->_count == 1)
		return (0);
	gr = lst_get(lst, 0);
	while (i < lst->_count)
	{
		gr2 = lst_get(lst, i);
		gr = comparer(gr, gr2);
		if (gr2 == gr)
			gr_i = i;
		i++;
	}
	return (gr_i);
}

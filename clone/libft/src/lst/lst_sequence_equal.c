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

/// @brief for comparing sequences are equals, for pointer type.
/// @return
bool	lst_sequence_equal_ptr(t_lst *lst,
							bool (*comparer)(t_lst *lst, int32_t index,
									t_lst *to_compare),
							t_lst *to_compare)
{
	int32_t	i;

	i = 0;
	if (lst->_count != to_compare->_count)
		return (false);
	while (i < lst->_count && i < to_compare->_count)
	{
		if (!comparer(lst, i, to_compare))
			return (false);
		i++;
	}
	return (true);
}

bool	lst_sequence_equal(t_lst *lst, t_lst *to_compare)
{
	int32_t	i;
	int32_t	j;
	uint8_t	*dat1;
	uint8_t	*dat2;

	i = 0;
	j = 0;
	if (lst->_count != to_compare->_count)
		return (false);
	while (i < lst->_count && i < to_compare->_count)
	{
		dat1 = lst_data(lst, i);
		dat2 = lst_data(to_compare, i);
		j = 0;
		while (j < lst->_size)
		{
			if (dat1[j] != dat2[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

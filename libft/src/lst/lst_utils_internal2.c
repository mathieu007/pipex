/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_internal2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:07:08 by mroy              #+#    #+#             */
/*   Updated: 2023/03/06 09:53:42 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

bool	_lst_can_add(t_lst *lst, int32_t elem_count)
{
	if (lst->_count + lst->_offset + elem_count < lst->_capacity)
	{
		return (true);
	}
	return (false);
}

/// @brief get middle addr + a custom offset.
/// @param lst
/// @param offset
/// @return
inline void	*_lst_addr_mid(t_lst *lst, int32_t offset)
{
	return ((void *)&lst->data[((lst->_capacity / 2) - (lst->_count / 2)
				+ offset) * lst->_size]);
}

/// @brief get middle offset + a custom offset.
/// @param lst
/// @param offset
/// @return
inline int32_t	_lst_offset_mid(t_lst *lst, int32_t offset)
{
	return ((lst->_capacity / 2) - (lst->_count / 2) + offset);
}

/// @brief get middle offset + a custom offset.
/// @param lst
/// @param offset
/// @return
inline int32_t	_lst_index_mid(t_lst *lst, int32_t offset)
{
	return (((lst->_capacity / 2) - (lst->_count / 2) + offset));
}

/// @brief get the adress at offset
/// @param lst
/// @param offset
/// @return
inline void	*_lst_addr_offset(t_lst *lst, int32_t offset)
{
	return (&lst->data[offset * lst->_size]);
}

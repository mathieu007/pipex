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

inline void	*lst_get(t_lst *lst, int32_t index)
{
	if (index >= lst->_count || index < 0)
		exit(139);
	return (*(void **)(&(lst->data[(index + lst->_offset) * lst->_size])));
}

inline void	**lst_addr_ptr(t_lst *lst, int32_t index)
{
	return ((void **)(&(lst->data[(index + lst->_offset) * lst->_size])));
}

/// @brief get the addresse at the index.
/// @param lst
/// @param index
/// @return
inline void	*lst_addr(t_lst *lst, int32_t index)
{
	return ((void *)(&(lst->data[(index + lst->_offset) * lst->_size])));
}

inline uint8_t	*lst_data(t_lst *lst, int32_t index)
{
	return (&lst->data[(lst->_offset + index) * lst->_size]);
}

inline int32_t	lst_get_int(t_lst *lst, int32_t index)
{
	if (index >= lst->_count || index < 0)
		exit(139);
	return (*(int32_t *)(&(lst->data[(index + lst->_offset) * lst->_size])));
}

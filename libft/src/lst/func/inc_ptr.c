/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_get_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:32:38 by mroy              #+#    #+#             */
/*   Updated: 2022/11/29 14:49:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

/// @brief increment pointer by x bytes
/// @param p
/// @param byte_size
/// @return
void	*inc_ptr(void *p, size_t byte_size)
{
	return ((void *)&((uint8_t *)p)[byte_size]);
}

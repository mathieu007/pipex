/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 09:33:44 by math              #+#    #+#             */
/*   Updated: 2023/02/23 13:13:36 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	*copy_temp(void *obj, size_t size_in_bytes)
{
	uint8_t	*new_obj;
	uint8_t	*obj_byte;

	obj_byte = (uint8_t *)obj;
	new_obj = temp_pool(size_in_bytes);
	while (size_in_bytes-- > 0)
	{
		new_obj[size_in_bytes] = obj_byte[size_in_bytes];
	}
	return ((void *)new_obj);
}

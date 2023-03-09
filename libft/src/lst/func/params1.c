/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_set_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2022/11/14 12:32:38 by mroy              #+#    #+#             */
/*   Updated: 2022/11/29 14:51:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

/// @brief WARNING data should have been assigned by p_values(size_t) function.
/// @param data
/// @param val
/// @return
void	add_int(void *data, int32_t val)
{
	int32_t	*byte_index;

	byte_index = &((int32_t *)data)[-1];
	*((int32_t *)&((uint8_t *)data)[*byte_index]) = val;
	*byte_index += sizeof(int32_t);
}

void	*p_values(size_t size)
{
	static uint8_t	*data[10000];
	static int32_t	index;

	index += size + sizeof(int32_t);
	if (index >= 10000)
	{
		index = 0;
		return (p_values(size));
	}
	*((int32_t *)data) = 0;
	return ((void *)&data[index - size]);
}

void	*p_int(int32_t value)
{
	static int32_t	data[10];
	static int32_t	index;

	index++;
	if (index >= 10)
		index = 0;
	data[index] = value;
	return ((void *)&data[index]);
}

void	*p_int2(int32_t value, int32_t value2)
{
	static int32_t	data[2];

	data[0] = value;
	data[1] = value2;
	return ((void *)&data[0]);
}

void	*p_uint(uint32_t value)
{
	static uint32_t	data[10];
	static int32_t	index;

	index++;
	if (index >= 10)
		index = 0;
	data[index] = value;
	return ((void *)&data[index]);
}

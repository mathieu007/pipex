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

void	*p_ulong(uint64_t value)
{
	static uint64_t	data[10];
	static int32_t	index;

	index++;
	if (index >= 10)
		index = 0;
	data[index] = value;
	return ((void *)&data[index]);
}

void	*p_long(int64_t value)
{
	static int64_t	data[10];
	static int32_t	index;

	index++;
	if (index >= 10)
		index = 0;
	data[index] = value;
	return ((void *)&data[index]);
}

void	*p_short(int16_t value)
{
	static int16_t	data[10];
	static int32_t	index;

	index++;
	if (index >= 10)
		index = 0;
	data[index] = value;
	return ((void *)&data[index]);
}

void	*p_ushort(uint16_t value)
{
	static uint16_t	data[10];
	static int32_t	index;

	index++;
	if (index >= 10)
		index = 0;
	data[index] = value;
	return ((void *)&data[index]);
}

void	*p_bool(bool value)
{
	static bool		data[10];
	static int32_t	index;

	index++;
	if (index >= 10)
		index = 0;
	data[index] = value;
	return ((void *)&data[index]);
}

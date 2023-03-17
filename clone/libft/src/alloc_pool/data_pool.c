/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_pool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 06:49:47 by math              #+#    #+#             */
/*   Updated: 2023/02/27 14:50:55 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_data_pool	*get_small_pool_data(void)
{
	static uint8_t		data[SMALL_POOL_SIZE];
	static t_data_pool	pool[1];

	if (pool->data == NULL)
	{
		pool->data = data;
		pool->capacity = SMALL_POOL_SIZE;
		pool->byte_used = 0;
	}
	return (&pool[0]);
}

t_data_pool	*get_med_pool_data(void)
{
	static uint8_t		data[MED_POOL_SIZE];
	static t_data_pool	pool[1];

	if (pool->data == NULL)
	{
		pool->data = data;
		pool->capacity = MED_POOL_SIZE;
		pool->byte_used = 0;
	}
	return (&pool[0]);
}

t_data_pool	*get_large_pool_data(void)
{
	static uint8_t		data[LARGE_POOL_SIZE];
	static t_data_pool	pool[1];

	if (pool->data == NULL)
	{
		pool->data = data;
		pool->capacity = LARGE_POOL_SIZE;
		pool->byte_used = 0;
	}
	return (&pool[0]);
}

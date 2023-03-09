/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_params_init.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:32:38 by mroy              #+#    #+#             */
/*   Updated: 2022/11/29 14:50:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	add_data_slots_large(t_pool_info *pool, int32_t segment_size)
{
	uint8_t		*dat;
	int32_t		i;
	t_data_pool	*data;

	data = get_large_pool_data();
	i = pool->capacity / 2;
	dat = data->data;
	if (data->byte_used + (i * segment_size) < data->capacity)
	{
		dat = &dat[data->byte_used];
		while (i < pool->capacity)
		{
			((int32_t *)dat)[0] = pool->chunk_size;
			((int32_t *)dat)[1] = i;
			pool->slots[i] = (void *)dat;
			dat = &dat[segment_size];
			i++;
		}
		return ;
	}
	exit(1);
}

static void	add_data_slots_med(t_pool_info *pool, int32_t segment_size)
{
	uint8_t		*dat;
	int32_t		i;
	t_data_pool	*data;

	data = get_med_pool_data();
	i = pool->capacity / 2;
	dat = data->data;
	if (data->byte_used + (i * segment_size) < data->capacity)
	{
		dat = &dat[data->byte_used];
		while (i < pool->capacity)
		{
			((int32_t *)dat)[0] = pool->chunk_size;
			((int32_t *)dat)[1] = i;
			pool->slots[i] = (void *)dat;
			dat = &dat[segment_size];
			i++;
		}
		return ;
	}
	add_data_slots_large(pool, segment_size);
}

static void	add_data_slots_sm(t_pool_info *pool, int32_t segment_size)
{
	uint8_t		*dat;
	int32_t		i;
	t_data_pool	*data;

	data = get_small_pool_data();
	if (pool->capacity == 2)
		i = 0;
	else
		i = pool->capacity / 2;
	dat = data->data;
	if (data->byte_used + (i * segment_size) < data->capacity)
	{
		dat = &dat[data->byte_used];
		while (i < pool->capacity)
		{
			((int32_t *)dat)[0] = pool->chunk_size;
			((int32_t *)dat)[1] = i;
			pool->slots[i] = (void *)dat;
			dat = &dat[segment_size];
			i++;
		}
		return ;
	}
	add_data_slots_med(pool, segment_size);
}

void	*resize_pool(t_pool_info *pool)
{
	uint8_t	**old;

	old = pool->slots;
	if (pool->capacity == 0)
		pool->capacity = 1;
	pool->capacity *= 2;
	pool->slots = malloc(sizeof(void *) * pool->capacity);
	if (pool->slots == NULL)
		return (NULL);
	if (pool->count > 0)
		ft_memcpy(pool->slots, old, pool->count * sizeof(void *));
	if (old != NULL)
		free(old);
	add_data_slots_sm(pool, pool->chunk_size + sizeof(int32_t));
	return ((void *)pool);
}

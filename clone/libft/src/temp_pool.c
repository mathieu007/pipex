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

#include "lst.h"

/// @brief using this data for temporary data.
/// it is a pool of memory, no need to malloc data if it is temporary.
/// warning do not use for storing long live data,
///	only for temp data manipulation.
/// @return
uint8_t	*temp_pool(int32_t size_in_bytes)
{
	static uint8_t	temp[TEMP_BUFFER];
	static int32_t	index;
	int32_t			i;

	index += size_in_bytes;
	if (index > TEMP_BUFFER)
		index = size_in_bytes;
	i = index - size_in_bytes;
	while (i < index)
	{
		temp[i] = 0;
		i++;
	}
	return (&temp[index - size_in_bytes]);
}

uint8_t	*temp_sort_pool(int32_t size_in_bytes)
{
	static uint8_t	temp[TEMP_SORT_DATA];
	static int32_t	index;
	int32_t			i;

	index += size_in_bytes;
	if (index > TEMP_SORT_DATA)
		index = size_in_bytes;
	i = index - size_in_bytes;
	while (i < index)
	{
		temp[i] = 0;
		i++;
	}
	return (&temp[index - size_in_bytes]);
}

uint8_t	*mem_pool(int32_t size_in_bytes)
{
	static uint8_t	fixed[FIXED_DATA_SIZE];
	static int32_t	index;
	const char		*err;

	err = "Error: You should allocate more memory to the fixed pool\n";
	index += size_in_bytes;
	if (index > FIXED_DATA_SIZE)
	{
		write(STDERR_FILENO, err, 58);
		exit(EXIT_FAILURE);
	}
	return (&fixed[index - size_in_bytes]);
}

t_group_by	*group_by_clause_pool(void)
{
	static t_group_by	temp[TEMP_MAX_GROUP_BY_CLAUSES];
	static int32_t		index;

	index++;
	if (index > TEMP_MAX_GROUP_BY_CLAUSES)
		index = 0;
	return (&temp[index]);
}

t_lst	**group_by_data_pool(int32_t num_of_group)
{
	static t_lst	*data[TEMP_MAX_GROUP_BY_DATA];
	static int32_t	index;

	index += num_of_group;
	if (index > TEMP_MAX_GROUP_BY_DATA)
		index = num_of_group;
	return (&data[index - num_of_group]);
}

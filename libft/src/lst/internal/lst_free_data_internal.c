/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_free_data_internal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:38:39 by marvin            #+#    #+#             */
/*   Updated: 2023/02/22 15:22:17 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	*_free_data_malloc(void *data)
{
	free(data);
	return (NULL);
}

void	*_free_data_fixed(void *data)
{
	(void)data;
	return (NULL);
}

void	*_free_data_temp(void *data)
{
	(void)data;
	return (NULL);
}

void	*_free_data_static(void *data)
{
	(void)data;
	return (NULL);
}

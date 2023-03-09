/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new_internal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 09:59:43 by marvin            #+#    #+#             */
/*   Updated: 2023/02/24 13:25:16 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	*_malloc(t_lst *lst, size_t size)
{
	(void)lst;
	return (malloc(size));
}

void	*_alloc_static(t_lst *lst, size_t size)
{
	(void)size;
	exit(138);
	return ((void *)lst->data);
}

void	*_alloc_temp(t_lst *lst, size_t size)
{
	(void)lst;
	return ((void *)temp_pool(size));
}

void	*_alloc_fixed(t_lst *lst, size_t size)
{
	(void)lst;
	return ((void *)mem_pool(size));
}

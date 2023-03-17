/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_free_internal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:38:39 by marvin            #+#    #+#             */
/*   Updated: 2023/02/22 15:22:17 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	*_free_malloc(t_lst *lst)
{
	if (!lst)
		return (NULL);
	if (!lst->data)
		return (free(lst), NULL);
	free(lst->data);
	return (NULL);
}

void	*_free_fixed(t_lst *lst)
{
	free(lst->data);
	return (NULL);
}

void	*_free_temp(t_lst *lst)
{
	free(lst->data);
	return (NULL);
}

void	*_free_static(t_lst *lst)
{
	(void)lst;
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:38:39 by marvin            #+#    #+#             */
/*   Updated: 2023/02/24 13:40:38 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	*lst_free(t_lst *lst)
{
	if (!lst)
		return (NULL);
	if (!lst->data)
		return (free(lst), NULL);
	free(lst->data);
	free(lst);
	return (NULL);
}

int32_t	*lst_free_func(t_lst *lst,
						void (*delete)(t_lst *lst))
{
	(*delete)(lst);
	if (lst && lst->data)
		free(lst->data);
	if (lst)
		free(lst);
	return (NULL);
}

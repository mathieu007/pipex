/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fclose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 08:05:04 by math              #+#    #+#             */
/*   Updated: 2023/03/06 09:54:13 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Closes the file descriptor and frees the buffer contained in the stream.
*/
int	ft_fclose(t_file **stream)
{
	if (!stream || !*stream)
		return (0);
	if (close((*stream)->fd) == -1)
		return (-1);
	free(*stream);
	*stream = NULL;
	return (0);
}

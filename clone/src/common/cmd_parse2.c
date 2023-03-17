/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:40:18 by math              #+#    #+#             */
/*   Updated: 2023/03/13 07:50:34 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_arg_start(char *cmd)
{
	int32_t	i;

	i = 0;
	while (cmd[i] && (cmd[i] == ' ' || cmd[i] == '\t'))
		i++;
	return (&cmd[i]);
}

char	*get_cmd_start(char *cmd)
{
	int32_t	i;

	i = 0;
	while (cmd[i] && (cmd[i] == ' ' || cmd[i] == '\t'))
		i++;
	return (&cmd[i]);
}

char	*get_cmd_end(char *cmd)
{
	int32_t	i;

	i = 0;
	while (cmd[i] && cmd[i] != ' ' && cmd[i] != '\t')
		i++;
	return (&cmd[i]);
}

char	*get_cmd(char *str)
{
	char	*cmd;
	int32_t	len;

	len = get_cmd_end(str) - str;
	cmd = malloc(len + 1);
	cmd[len] = '\0';
	ft_strncpy(cmd, str, len);
	return (cmd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:40:18 by math              #+#    #+#             */
/*   Updated: 2023/03/14 14:13:44 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// bool	isbuiltin(char *cmd)
// {
// 	char	*args[3];
// 	char	*joined;

// 	args[0] = "sh";
// 	args[1] = "-c";
// 	joined = ft_strjoin("'type ", cmd);
// 	if (!joined)
// 		free_err_exit(EXIT_FAILURE);
// 	args[2] = ft_strjoin(joined, "'");
// 	if (!joined)
// 		free_err_exit(EXIT_FAILURE);
// 	free(joined);
// }

// bool	cmd_type(char *cmd)
// {
// 	char	*args[3];
// 	char	*joined;

// 	args[0] = "sh";
// 	args[1] = "-c";
// 	joined = ft_strjoin("'type ", cmd);
// 	if (!joined)
// 		free_err_exit(EXIT_FAILURE);
// 	args[2] = ft_strjoin(joined, "'");
// 	if (!joined)
// 		free_err_exit(EXIT_FAILURE);
// 	free(joined);
// }

// char	*output_execve(void)
// {
// 	int		link[2];
// 	pid_t	pid;
// 	char	foo[4096];
// 	int		nbytes;

// 	if (pipe(link) == -1)
// 		die("pipe");
// 	if ((pid = fork()) == -1)
// 		die("fork");
// 	if (pid == 0)
// 	{
// 		dup2(link[1], STDOUT_FILENO);
// 		close(link[0]);
// 		close(link[1]);
// 		execl("/bin/ls", "ls", "-1", (char *)0);
// 		die("execl");
// 	}
// 	else
// 	{
// 		close(link[1]);
// 		nbytes = read(link[0], foo, sizeof(foo));
// 		printf("Output: (%.*s)\n", nbytes, foo);
// 		wait(NULL);
// 	}
// }

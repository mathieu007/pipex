/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 08:02:59 by math              #+#    #+#             */
/*   Updated: 2023/03/13 20:52:52 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/// @brief test
/// @param
void	usage(void)
{
	printf("Invalid argument count.\n");
	printf("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n");
	free_exit(EXIT_FAILURE);
}

int32_t	main(int32_t argc, char **argv, char **envp)
{
	t_proc	*proc;

	if (argc < 5)
		usage();
	proc = init_data(argc, argv, envp);
	open_files(proc);
	pipe_childs(proc);
	exec_childs(proc);
	if (proc->error)
		free_exit(EXIT_FAILURE);
	else
		free_all();
	return (0);
}

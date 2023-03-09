/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 08:02:59 by math              #+#    #+#             */
/*   Updated: 2023/03/09 10:47:29 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	usage(void)
{
	printf("Invalid argument count.\n");
	printf("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n");
	error_exit(NULL, 1, false);
}

int32_t	main(int32_t argc, char **argv, char **envp)
{
	t_proc	*proc;
	int32_t	f_out;

	if (argc < 5)
		usage();
	proc = init_data(argc, argv, envp);
	f_out = open_files(proc);
	pipe_childs(proc);
	exec_childs(proc);
	dup2(f_out, STDOUT_FILENO);
	execute(proc, proc->cmds_count - 1);
	free_all();
	return (0);
}

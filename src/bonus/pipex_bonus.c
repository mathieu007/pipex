/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 08:02:59 by math              #+#    #+#             */
/*   Updated: 2023/03/10 13:18:36 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	usage_bonus(void)
{
	printf("Invalid arguments count.");
	printf("Example: ./pipex <file_in> <cmd1> <cmd2> <...> <file_out>\n");
	printf("Example: ./pipex \"here_doc\" <LIMITER> <cmd>"
		"<cmd1> <...> <file_out>\n");
	error_exit(NULL, 1, false, 1);
}

void	write_line(char *sep, int32_t fd_in, int32_t fd_out)
{
	char	*line;
	int32_t	sep_len;

	close(fd_in);
	sep_len = ft_strlen(sep);
	line = get_next_line_temp(STDIN_FILENO);
	while (line)
	{
		if (ft_strncmp(line, sep, sep_len) == 0)
			exit(EXIT_SUCCESS);
		write(fd_out, line, ft_strlen(line));
		line = get_next_line_temp(STDIN_FILENO);
	}
}

void	here_doc(char *sep, int argc)
{
	pid_t	pid;
	int32_t	fds[2];

	if (argc < 6)
		usage_bonus();
	if (pipe(fds) == -1)
		error_exit(NULL, 2, true, 1);
	init_fds(fds, 0);
	pid = fork();
	if (pid == -1)
		error_exit(NULL, 2, true, 1);
	if (pid == 0)
		write_line(sep, fds[0], fds[1]);
	else
	{
		close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
		wait(NULL);
	}
}

int32_t	open_files_bonus(t_proc *proc, int32_t argc, char **argv)
{
	int32_t	f_out;

	if (proc->here_doc)
	{
		proc->here_doc = true;
		f_out = open(proc->f_out_name, O_WRONLY | O_CREAT | O_APPEND, 0777);
		here_doc(argv[2], argc);
	}
	else
		f_out = open_files(proc);
	return (f_out);
}

int32_t	main(int32_t argc, char **argv, char **envp)
{
	t_proc	*proc;
	int32_t	f_out;

	if (argc < 6)
		usage_bonus();
	proc = init_data(argc, argv, envp);
	f_out = open_files_bonus(proc, argc, argv);
	pipe_childs(proc);
	exec_childs(proc);
	dup2(f_out, STDOUT_FILENO);
	execute(proc, proc->cmds_count - 1);
	return (0);
}

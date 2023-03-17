/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 08:02:59 by math              #+#    #+#             */
/*   Updated: 2023/03/16 12:24:07 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	usage_bonus(void)
{
	printf("Invalid arguments count.");
	printf("Example: ./pipex <file_in> <cmd1> <cmd2> <...> <file_out>\n");
	printf("Example: ./pipex \"here_doc\" <LIMITER> <cmd>"
		"<cmd1> <...> <file_out>\n");
	free_exit(EXIT_FAILURE);
}

void	write_line(char *sep, int32_t fd_in, int32_t fd_out)
{
	char	*line;
	int32_t	sep_len;

	sep_len = ft_strlen(sep);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (ft_strncmp(line, sep, sep_len) == 0 && line[sep_len] == '\n')
		{
			close(fd_in);
			close(fd_out);
			exit(EXIT_SUCCESS);
		}
		write(fd_out, line, ft_strlen(line));
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	close(fd_in);
	close(fd_out);
	exit(EXIT_FAILURE);
}

void	here_doc(char *sep, int argc)
{
	pid_t	pid;
	int32_t	fds[2];

	if (argc < 6)
		usage_bonus();
	if (pipe(fds) == -1)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
		write_line(sep, fds[0], fds[1]);
	else
	{
		dup2(fds[0], STDIN_FILENO);
		close(fds[1]);
		close(fds[0]);
		wait(NULL);
	}
}

int32_t	main(int32_t argc, char **argv, char **envp)
{
	t_proc	*proc;

	proc = NULL;
	if (argc < 6)
		usage_bonus();
	proc = init_data(argc, argv, envp);
	open_files(proc);
	if (proc->here_doc)
		here_doc(argv[2], argc);
	pipe_childs(proc);
	exec_childs(proc);
	if (!proc->command_found)
		free_exit(EXIT_FAILURE);
	else
		free_all();
	return (0);
}

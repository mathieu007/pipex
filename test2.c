/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 22:40:28 by math              #+#    #+#             */
/*   Updated: 2023/03/13 10:57:48 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errno.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#include <unistd.h>

static void	dump_argv(char **argv)
{
	printf("%d:\n", getpid());
	while (*argv != NULL)
	{
		printf("%d: <<%s>>\n", getpid(), *argv++);
	}
}

static void	sendbc(char *str)
{
	int		fd1[2];
	int		fd2[2];
	int		fd3[2];
	int		pid;
	int		pid2;
	int		pid3;
	int		f_out;
	int		f_in;
	int		status;
	pid_t childs[3];

	char	*echo[3] = {"grep", "Now", NULL};
	char	*sed1[3] = {"sleep", "3", NULL};
	char	*sed2[3] = {"exit", "5", NULL};
	f_in = open("./infile2", O_RDONLY, 0777);
	if (f_in == -1)
		f_in = open("./assets/deepthought.txt", O_RDONLY, 0777);
	f_out = open("./outs/test-08.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(f_out, STDOUT_FILENO);
	dup2(f_in, STDIN_FILENO);
	close(f_out);
	close(f_in);
	if (pipe(fd1) < 0)
		exit(100);
	// if (pipe(fd2) < 0)
	// 	exit(101);
	if (pipe(fd3) < 0)
		exit(101);
	pid = fork();
	if (pid < 0)
		exit(102);
	else if (pid == 0)
	{
		printf("%d: child 1 - echo\n", getpid());
		//dump_argv(echo);
		dup2(fd1[1], 1);
		close(fd1[1]);
		close(fd1[0]);
		close(fd3[0]);
		close(fd3[1]);
		execvp(echo[0], echo);
		fprintf(stderr, "Error in execvp1\n");
		exit(103);
	}
	childs[0] = pid;

	// pid2 = fork();
	// if (pid2 < 0)
	// 	exit(102);
	// if (pid2 == 0)
	// {
	// 	printf("%d: child 2 - sed 1\n", getpid());
	// 	//dump_argv(sed1);
	// 	dup2(fd1[0], 0);
	// 	dup2(fd2[1], 1);
	// 	close(fd1[1]);
	// 	close(fd1[0]);
	// 	close(fd2[1]);
	// 	close(fd2[0]);
	// 	execvp(sed1[0], sed1);
	// 	fprintf(stderr, "Error in execvp2\n");
	// 	exit(104);
	// }
	// childs[1] = pid2;

	pid3 = fork();
	if (pid3 < 0)
		exit(102);
	if (pid3 == 0)
	{
		printf("%d: child 3 - sed 2\n", getpid());
		dup2(fd1[0], 0);
		close(fd1[1]);
		close(fd1[0]);
		close(fd3[1]);
		close(fd3[0]);
		close(f_out);
		close(f_in);
		execvp(sed2[0], sed2);
		fprintf(stderr, "Error in execvp2\n");
		exit(104);
	}
	childs[1] = pid3;
		
	for(int i = 0; i < 2; i++)
	{
		pid_t child = childs[i];

		int status;
		waitpid(child, &status, WNOHANG);
	}
	
}

int	main(void)
{
	int status;
	char message[243] =
		"This is the first line\n"
		"and this is the second - with a semicolon ; here before a :\n"
		"and the third line has a colon : before the semicolon ;\n"
		"but the fourth line has a dot . before the colon\n"
		"whereas the fifth line has a colon : before the dot .\n";

	sendbc(message);
	
	return (0);
}
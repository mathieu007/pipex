/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:21:35 by mroy              #+#    #+#             */
/*   Updated: 2023/03/10 13:18:52 by mroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "errno.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_cmd
{
	char	**args;
	char	*cmd;
	int32_t	file_in;
	int32_t	file_out;
	pid_t	pid;
}			t_cmd;

typedef struct s_proc
{
	bool	here_doc;
	char	**paths;
	t_cmd	**cmds;
	int32_t	f_in;
	int32_t	f_out;
	char	*f_in_name;
	char	*f_out_name;
	int32_t	cmds_count;
	char	**envp;
}			t_proc;

int32_t		open_files(t_proc *proc);
void		unlink_fifo(char *f_name);
void		usage(void);
void		error_exit(const char *msg, int32_t stderror, bool show_error_msg,
				int32_t exit_code);
void		execute(t_proc *proc, int32_t i);
void		child_process(t_proc *proc, int32_t cmd_i);
char		**parse_paths(char **envp);
t_cmd		**parse_cmds(t_proc *proc, char **argv, int32_t count);
void		pipe_childs(t_proc *proc);
char		*get_full_path_cmd(t_proc *proc, char *cmd);
void		free_all(void);
t_proc		*get_proc(void);
t_proc		*init_data(int32_t argc, char **argv, char **envp);
t_proc		*init_fds(int32_t *fds, int32_t i);
void		exec_childs(t_proc *proc);
void		write_msg(const char *msg, int32_t stderror, bool with_lf);
void		write_error(int32_t stderror, bool with_lf);
char		*get_cmd(char *str);
char		*get_arg_start(char *cmd);
char		*get_cmd_start(char *cmd);
char		*get_cmd_end(char *cmd);
char		*get_cmd(char *str);

#endif

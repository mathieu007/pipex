/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 08:02:59 by math              #+#    #+#             */
/*   Updated: 2023/03/16 06:53:23 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_proc	*get_proc(void)
{
	static t_proc	proc[1];

	return (&proc[0]);
}

t_proc	*init_fds(int32_t *fds, int32_t i)
{
	t_proc	*proc;

	proc = get_proc();
	proc->cmds[i]->file_in = fds[0];
	proc->cmds[i]->file_out = fds[1];
	return (&proc[0]);
}

char	*get_file_name(char *f_name, t_proc *proc)
{
	char	*full_path;

	if (ft_strstartwith(f_name, "../") || ft_strstartwith(f_name, "./")
		|| ft_strstartwith(f_name, "/"))
		return (strdup(f_name));
	full_path = ft_strjoin(proc->pwd, f_name);
	if (full_path == NULL)
		return (free_err_exit(EXIT_FAILURE));
	return (full_path);
}

t_proc	*init_data(int32_t argc, char **argv, char **envp)
{
	t_proc	*proc;

	proc = get_proc();
	proc->here_doc = false;
	proc->pwd = parse_pwd(envp);
	proc->paths = parse_paths(envp);
	proc->envp = envp;
	proc->f_out_name = get_file_name(argv[argc - 1], proc);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		proc->f_in_name = NULL;
		proc->here_doc = true;
		proc->cmds_count = argc - 4;
		proc->cmds = parse_cmds(proc, &argv[3], proc->cmds_count);
	}
	else
	{
		proc->f_in_name = get_file_name(argv[1], proc);
		proc->here_doc = false;
		proc->cmds_count = argc - 3;
		proc->cmds = parse_cmds(proc, &argv[2], proc->cmds_count);
	}
	if (!proc->cmds || !proc->f_out_name || !proc->f_in_name)
		return (free_err_exit(STDERR_FILENO));
	return (&proc[0]);
}

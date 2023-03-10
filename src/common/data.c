/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroy <mroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 08:02:59 by math              #+#    #+#             */
/*   Updated: 2023/03/10 14:11:30 by mroy             ###   ########.fr       */
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

t_proc	*init_data(int32_t argc, char **argv, char **envp)
{
	t_proc	*proc;

	proc = get_proc();
	proc->here_doc = false;
	if (ft_strncmp(argv[1], "./", 2) != 0)
		proc->f_in_name = ft_strjoin("./", argv[1]);
	if (ft_strncmp(argv[1], "./", 2) != 0)
		proc->f_out_name = ft_strjoin("./", argv[argc - 1]);
	proc->paths = parse_paths(envp);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		proc->here_doc = true;
		proc->cmds_count = argc - 4;
		proc->cmds = parse_cmds(proc, &argv[3], proc->cmds_count);
	}
	else
	{
		proc->here_doc = false;
		proc->cmds_count = argc - 3;
		proc->cmds = parse_cmds(proc, &argv[2], proc->cmds_count);
	}
	if (proc->cmds == NULL)
		return (free_all(), NULL);
	proc->envp = envp;
	return (&proc[0]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 10:56:26 by atrouill          #+#    #+#             */
/*   Updated: 2021/11/15 14:40:30 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

int	heredocs(t_list **cmds)
{
	char	*hd;
	int		fd[2];
	int		ret;

	if (g_glob->tmp_fdout != 0)
	{
		dup2(g_glob->tmp_fdout, 1);
		close(g_glob->tmp_fdout);
	}
	pipe(fd);

	g_glob->tmp_pid = fork();
	if (g_glob->tmp_pid == 0)
	{
		hd = input_heredocs(cmds);
		if (hd != NULL /*&& g_glob->interrupt_flag_set == 0*/)
		{
			dup2(fd[0], 0);
			ft_putstr_fd(((char *)hd), fd[1]);
			close(fd[0]);
			close(fd[1]);
		}
		free(hd);
		exit(0);
	}
	dprintf(2, "Before wait with pid [%d]\n", g_glob->tmp_pid);
	waitpid(-1, &ret, 0);
	dprintf(2, "After wait with pid [%d]\n", g_glob->tmp_pid);
	close(fd[0]);
	close(fd[1]);
	g_glob->heredocs = false;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 10:56:26 by atrouill          #+#    #+#             */
/*   Updated: 2021/11/30 11:29:24 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

static int	heredocs_helpers(t_list *cmd)
{
	char	*hd;
	int		fd;

	hd = input_heredocs(cmd);
	if (hd != NULL)
	{
		fd = open("./.here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
		ft_putstr_fd(hd, fd);
		close(fd);
	}
	free(hd);
	exit(0);
}

int	heredocs(t_list	*cmd, int *fdin)
{
	int		ret;
	int		tmp_fd;

	g_glob->prog = 1;
	g_glob->tmp_pid = fork();
	if (g_glob->tmp_pid == 0)
	{
		signal(SIGINT, int_child_handler);
		heredocs_helpers(cmd);
	}
	waitpid(g_glob->tmp_pid, &ret, 0);
	g_glob->prog = 0;
	tmp_fd = open("./.here_doc", O_RDONLY);
	if (tmp_fd > 0)
	{
		if (*fdin != 0)
			close(*fdin);
		(*fdin) = tmp_fd;
	}
	g_glob->tmp_pid = 0;
	g_glob->heredocs = false;
	if (tmp_fd < 0)
		return (-1);
	return (0);
}

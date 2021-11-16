/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 10:56:26 by atrouill          #+#    #+#             */
/*   Updated: 2021/11/16 15:42:23 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

int	heredocs(t_list	*cmd, int *fdin)
{
	char	*hd;
	int		ret;
	int		fd;


	g_glob->prog = 1;
	g_glob->tmp_pid = fork();
	if (g_glob->tmp_pid == 0)
	{
		hd = input_heredocs(cmd);
		if (hd != NULL)
		{
			fd = open(".here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
			ft_putstr_fd(hd, fd);
			close(fd);
		}
		free(hd);
		exit(0);
	}
	waitpid(g_glob->tmp_pid, &ret, 0);
	g_glob->prog = 0;
	if (*fdin != 0)
		close(*fdin);
	(*fdin) = open(".here_doc", O_RDONLY);
	g_glob->tmp_pid = 0;
	g_glob->heredocs = false;
	if (*fdin < 0)
		return (-1);
	return (0);
}

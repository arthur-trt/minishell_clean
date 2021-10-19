/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 10:56:26 by atrouill          #+#    #+#             */
/*   Updated: 2021/10/19 13:44:11 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

int	heredocs(t_list **cmds)
{
	char	*hd;
	int		fd[2];

	hd = input_heredocs(cmds);
	if (hd != NULL)
	{
		if (g_glob->tmp_fdout != 0)
		{
			dup2(g_glob->tmp_fdout, 1);
			close(g_glob->tmp_fdout);
		}
		pipe(fd);
		dup2(fd[0], 0);
		ft_putstr_fd(((char *)hd), fd[1]);
		free(hd);
		close(fd[0]);
		close(fd[1]);
	}
	g_glob->heredocs = false;
	return (0);
}

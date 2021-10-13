/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 10:56:26 by atrouill          #+#    #+#             */
/*   Updated: 2021/10/13 11:30:14 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

static char	*find_delimiter(t_list *cmds)
{
	t_list	*tmp;
	int		i;
	char	*eof;

	tmp = cmds;
	eof = NULL;
	while (tmp)
	{
		i = 0;
		while (tmp && tmp->content[i])
		{
			if (ft_ischarset(tmp->content[i], "<>"))
			{
				tmp = tmp->next;
				if (eof != NULL)
					free(eof);
				if (tmp)
					eof = ft_strdup(tmp->content);
			}
			i++;
		}
		if (tmp)
			tmp = tmp->next;
	}
	return (eof);
}

static char	*check_error_del(t_list *cmds)
{
	char *eof;

	eof = find_delimiter(cmds);
	if (eof == NULL)
	{
		ft_putstrerror(NULL, "syntax error near unexpected token");
		free(eof);
		return (NULL);
	}
	return (eof);
}


int	heredocs(t_list *cmds)
{
	char	*hd;
	int		fd[2];
	char	*eof;

	eof = check_error_del(cmds);
	if (eof == NULL)
		return (1);
	hd = input_heredocs(eof);
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
	g_glob->heredocs = false;
	return (0);
}

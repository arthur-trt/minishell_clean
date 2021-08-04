/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 10:56:26 by atrouill          #+#    #+#             */
/*   Updated: 2021/08/04 15:00:52 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

static char	*find_delimiter(t_list *cmds)
{
	t_list	*tmp;
	int		i;

	tmp = cmds;
	while (tmp)
	{
		i = 0;
		while (tmp->content[i])
		{
			if (ft_ischarset(tmp->content[i], "<>"))
			{
				tmp = tmp->next;
				return (tmp->content);
			}
			i++;
		}
		tmp = tmp->next;
	}
	return (0);
}

int		heredocs(t_list *cmds)
{
	char	*hd;
	int		fd[2];

	hd = input_heredocs(find_delimiter(cmds));
	pipe(fd);
	dup2(fd[0], 0);
	ft_putstr_fd(((char *)hd), fd[1]);
	free(hd);
	close(fd[0]);
	close(fd[1]);
	g_glob->heredocs = false;
	return (0);
}

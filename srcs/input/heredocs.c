/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:24:31 by atrouill          #+#    #+#             */
/*   Updated: 2021/10/18 14:33:28 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*input_loop(char *del)
{
	char	*tmp;
	char	*hd;

	tmp = readline("> ");
	if (tmp)
		hd = ft_strdup(tmp);
	else
		hd = ft_strdup("\0");
	while (tmp && tmp[0] != '\0' && ft_strcmp(tmp, del) != 0)
	{
		free(tmp);
		tmp = readline("> ");
		if (tmp && ft_strcmp(tmp, del) != 0)
		{
			ft_strjoin_gnl(&hd, "\n");
			ft_strjoin_gnl(&hd, tmp);
		}
	}
	ft_strjoin_gnl(&hd, "\n");
	return (hd);
}

char	*input_heredocs(t_list *cmds)
{
	t_list	*tmp;
	char	*hd;
	char	*hd_expand;

	tmp = cmds;
	hd = NULL;
	while (tmp)
	{
		if (ft_strcontain(tmp->content, '<'))
		{
			if (tmp->next)
			{
				tmp = tmp->next;
				if (hd != NULL)
					free(hd);
				hd = input_loop(tmp->content);
				if (tmp->d_quote == 0)
				{
					hd_expand = expand_var(hd);
					free(hd);
					hd = hd_expand;
				}
			}
		}
		tmp = tmp->next;
	}
	return (hd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:24:31 by atrouill          #+#    #+#             */
/*   Updated: 2021/10/20 17:19:33 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

static char	*readline_wrapper(char *prompt, char *del)
{
	char	*tmp;
	(void)prompt;

	//rl_catch_signals = 0;
	ft_putstr_fd("> ", 1);
	get_next_line(0, &tmp);
	if (tmp == NULL)
	{
		ft_putstr_fd("minishell: warning: here-document delimited", 2);
		ft_putstr_fd(" by end-of-file (wanted `", 2);
		ft_putstr_fd(del, 2);
		ft_putstr_fd("')\n", 2);
	}
	return (tmp);
}

static char	*input_loop(char *del)
{
	char	*tmp;
	char	*hd;

	tmp = readline_wrapper("> ", del);
	if (tmp)
		hd = ft_strdup(tmp);
	else
		hd = ft_strdup("\0");
	while (tmp && ft_strcmp(tmp, del) != 0)
	{
		free(tmp);
		tmp = readline_wrapper("> ", del);
		if (tmp && ft_strcmp(tmp, del) != 0)
		{
			ft_strjoin_gnl(&hd, "\n");
			ft_strjoin_gnl(&hd, tmp);
		}
	}
	free(tmp);
	ft_strjoin_gnl(&hd, "\n");
	return (hd);
}

char	*input_heredocs(t_list **cmds)
{
	t_list	*tmp;
	char	*hd;
	char	*hd_expand;

	tmp = (*cmds);
	hd = NULL;
	while (tmp)
	{
		if (ft_strcontain(tmp->content, '<'))
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
		tmp = tmp->next;
	}
	clean_cmds_heredocs(cmds);
	return (hd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_cleaner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:22:36 by atrouill          #+#    #+#             */
/*   Updated: 2021/11/30 13:43:09 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_redirect(char *s)
{
	if (ft_strcmp(">", s) == 0
		|| ft_strcmp(">>", s) == 0
		|| ft_strcmp("<", s) == 0
		|| ft_strcmp("<<", s) == 0)
	{
		return (true);
	}
	return (false);
}

static void	free_all(t_list **cmds)
{
	t_list	*tmp;

	tmp = *(cmds);
	free(tmp->next->content);
	tmp->next->content = NULL;
	free(tmp->content);
	tmp->content = NULL;
	free(tmp->next);
	tmp->next = NULL;
	free(tmp);
	tmp = NULL;
}

void	clean_cmds(t_list **cmds)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *(cmds);
	if (is_redirect(tmp->content) && tmp->d_quote == 0 && tmp->esc == 0)
			*cmds = tmp->next->next;
	else
	{
		while (tmp != NULL && (!is_redirect(tmp->content)
				|| tmp->d_quote != 0 || tmp->esc != 0))
		{
			prev = tmp;
			tmp = tmp->next;
		}
		if (tmp == NULL)
			return ;
		prev->next = tmp->next->next;
	}
	free_all(&tmp);
}

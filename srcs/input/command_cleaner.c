/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_cleaner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:22:36 by atrouill          #+#    #+#             */
/*   Updated: 2021/11/18 17:45:20 by atrouill         ###   ########.fr       */
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

void	clean_input(t_list **cmds)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *(cmds);
	while (tmp != NULL)
	{
		prev = tmp;
		if (is_redirect(tmp->content) && tmp->d_quote == 0 && tmp->esc == 0)
		{


		}
	}
}

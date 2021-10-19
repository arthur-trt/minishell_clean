/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs_clean_cmds.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:01:29 by atrouill          #+#    #+#             */
/*   Updated: 2021/10/19 12:09:10 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean_cmds_heredocs(t_list **cmds)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *cmds;
	if (tmp != NULL && ft_strcmp(tmp->content, "<<") == 0)
		*cmds = tmp->next->next;
	else
	{
		while (tmp != NULL && ft_strcmp(tmp->content, "<<") != 0)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		if (tmp == NULL)
			return ;
		prev->next = tmp->next->next;
	}
	free(tmp->next->content);
	tmp->next->content = NULL;
	free(tmp->content);
	tmp->content = NULL;
	free(tmp->next);
	tmp->next = NULL;
	free(tmp);
	tmp = NULL;
}

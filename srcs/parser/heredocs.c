/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 10:56:26 by atrouill          #+#    #+#             */
/*   Updated: 2021/07/28 15:46:39 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

t_list	*heredocs(t_list *cmds)
{
	char	*arg;

	arg = input_heredocs(find_delimiter(cmds));
	cmds->content = arg;
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 14:22:27 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/08 15:10:21 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	has_space(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ')
			return (true);
		i++;
	}
	return (false);
}

void	ft_check_parser(t_list **cmd)
{
	char	**splited;
	t_list	*next;
	t_list	*new;
	t_list	*tmp;

	tmp = *cmd;
	while (tmp != NULL)
	{
		if (has_space(tmp->content) && tmp->expanded == 1 && tmp->d_quote == 0)
		{
			splited = ft_split(tmp->content, ' ');
			free(tmp->content);
			tmp->content = splited[0];
			next = tmp->next;
			new = ft_lstnew(splited[1]);
			new->next = next;
			tmp->next = new;
		}
		tmp = tmp->next;
	}
}

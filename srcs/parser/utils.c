/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:31:24 by jcueille          #+#    #+#             */
/*   Updated: 2021/09/20 12:15:14 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include <stdio.h>

/*
**	Free a linked list and its content
**
**	@param	lst the linked list to free
**	@return void
*/
void	ft_listclear(t_list **lst)
{
	t_list	*nxt;
	t_list	*tmp;

	if (*lst)
	{
		tmp = *lst;
		while (tmp)
		{
			nxt = (tmp)->next;
			free(tmp->content);
			tmp->content = NULL;
			free(tmp);
			tmp = nxt;
		}
		*lst = NULL;
	}
}

int	double_checker(char *s, int *i, char **res, t_list *command)
{
	int	r;

	r = 0;
	if (s[*i + 1] != '\"')
	{
		r = ft_apply_double(s, i, &ft_double, res);
		if (r != 0)
			return (ft_double_error(r, command, *res));
	}
	else
	{
		*res = ft_strdup("");
		(*i) += 1;
		return (1);
	}
	return (0);
}

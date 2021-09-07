/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copycmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 13:53:23 by jcueille          #+#    #+#             */
/*   Updated: 2021/09/07 19:49:53 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	copycmds_util(t_list **res, t_list *tmp, char *s)
{
	t_list	*tmpbis;

	if (!((*res)))
	{
		(*res) = ft_lstnew(s);
		(*res)->d_quote = tmp->d_quote;
	}
	else
	{
		tmpbis = ft_lstnew(s);
		tmpbis->d_quote = tmp->d_quote;
		ft_lstadd_back(res, tmpbis);
	}
}

/*
*** copy the commands into a t_list * and stops at the redirection symbol
*** @param t_list*lst the list to copy
*** @return t_list *res the copied list
*/
t_list	*copycmds(t_list *lst)
{
	t_list	*res;
	t_list	*tmp;
	char	*s;
	int		r;

	tmp = lst;
	s = NULL;
	r = 0;
	res = NULL;
	while (tmp)
	{
		r = word_checker(tmp, &s);
		copycmds_util(&res, tmp, s);
		if (r)
			break ;
		tmp = tmp->next;
	}
	return (res);
}

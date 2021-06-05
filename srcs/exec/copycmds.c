/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copycmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 13:53:23 by jcueille          #+#    #+#             */
/*   Updated: 2021/06/04 12:39:27 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"


/*
*** copy the commands into a t_list * and stops at the redirection symbol
*** @param t_list*lst the list to copy
*** @return t_list *res the copied list
*/
t_list		*copycmds(t_list *lst)
{
	t_list	*res;
	t_list	*tmp;
	t_list	*tmpbis;
	char	*s;
	int		r;

	tmp = lst;
	s = NULL;
	r = 0;
	res = NULL;
	while (tmp)
	{
		r = word_checker(tmp, &s);
		if (!(res))
			res = ft_lstnew(s);
		else
		{
			tmpbis = ft_lstnew(s);
			ft_lstadd_back(&res, tmpbis);
		}
		if (r)
			break ;
		tmp = tmp->next;
	}
	return (res);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copycmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 13:53:23 by jcueille          #+#    #+#             */
/*   Updated: 2021/05/30 19:50:40 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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
	printf("entering copycmds\n");
	while (tmp)
	{
		r = word_checker(tmp, &s);
		printf("s is %s\n", s);
		// s = ft_strdup(tmp->content);
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
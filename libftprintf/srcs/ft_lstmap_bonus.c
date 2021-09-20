/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 10:32:44 by atrouill          #+#    #+#             */
/*   Updated: 2021/08/13 19:43:25 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static t_list	*ft_lstmatp_helper(t_list *lst, void *(*f)(void *),
	void (*del)(void *))
{
	t_list	*new_list;
	t_list	*begin;
	t_list	*tmp;

	tmp = lst;
	begin = ft_lstnew(f(tmp->content));
	if (!(begin))
		return (NULL);
	tmp = lst->next;
	while (tmp)
	{
		new_list = ft_lstnew(f(tmp->content));
		if (!(new_list))
		{
			ft_lstclear(&begin, del);
			return (NULL);
		}
		ft_lstadd_back(&begin, new_list);
		tmp = tmp->next;
	}
	free(tmp);
	return (begin);
}

/*
**	Itere on a list and applies a function to the content of each element.
**	Creates a new list resulting from successive applications of f.
**
**	@param lst Original list
**	@param f Pointer to a function, will be applied to each element
**	@param del Pointer to a function, delete an element
**
**	@return Pointer to the first element of the new list
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	if (lst)
	{
		return (ft_lstmatp_helper(lst, f, del));
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 10:32:44 by atrouill          #+#    #+#             */
/*   Updated: 2021/03/08 11:46:52 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

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
	t_list	*new_list;
	t_list	*begin;
	t_list	*tmp;

	if (lst)
	{
		tmp = lst;
		if (!(begin = ft_lstnew(f(tmp->content))))
			return (NULL);
		tmp = lst->next;
		while (tmp)
		{
			if (!(new_list = ft_lstnew(f(tmp->content))))
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
	return (NULL);
}

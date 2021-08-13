/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 10:27:50 by atrouill          #+#    #+#             */
/*   Updated: 2021/03/08 11:38:11 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
**	Apply a function to all elements of a list
**
**	@param alst Linked list to modify
**	@param f Pointer to a function
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	tmp = lst;
	if (lst)
		while (tmp)
		{
			f(tmp->content);
			tmp = tmp->next;
		}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 22:01:17 by atrouill          #+#    #+#             */
/*   Updated: 2021/03/08 11:49:43 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
**	Obtain the size of a linked list
**
**	@param lst Linked list
**
**	@return Size of the linked list
*/
int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		elem;

	elem = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		elem++;
	}
	return (elem);
}

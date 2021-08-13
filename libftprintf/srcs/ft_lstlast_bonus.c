/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 22:07:23 by atrouill          #+#    #+#             */
/*   Updated: 2021/03/08 11:39:18 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
**	Return the last element of a linked list
**
**	@param lst Linked list where to search
**
**	@return Pointer to last element
*/
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (tmp)
		while (tmp->next)
			tmp = tmp->next;
	return (tmp);
}

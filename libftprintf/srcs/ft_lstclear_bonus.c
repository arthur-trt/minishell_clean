/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 09:57:26 by atrouill          #+#    #+#             */
/*   Updated: 2021/03/08 11:31:34 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
**	Delete all element of a list
**
**	@param lst Linked list to clear
**	@param del Pointer to function wich delete element
*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (lst)
		while (*lst)
		{
			tmp = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = tmp;
		}
}

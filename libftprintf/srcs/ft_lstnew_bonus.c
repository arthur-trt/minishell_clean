/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 21:14:45 by atrouill          #+#    #+#             */
/*   Updated: 2021/03/08 11:47:52 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
**	Create new element for a linked list
**
**	@param content Pointer to the content to add in the element
**
**	@return Pointer on the new element 
*/
t_list	*ft_lstnew(void *content)
{
	t_list *res;

	if (!(res = malloc(sizeof(t_list))))
		return (NULL);
	res->content = content;
	res->next = NULL;
	return (res);
}

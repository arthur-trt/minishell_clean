/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 21:14:45 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/09 13:54:17 by atrouill         ###   ########.fr       */
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
	t_list	*res;

	res = malloc(sizeof(t_list));
	if (!(res))
		return (NULL);
	res->content = content;
	res->d_quote = 0;
	res->expanded = 0;
	res->esc = 0;
	res->next = NULL;
	return (res);
}

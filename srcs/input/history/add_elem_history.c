/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_elem_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 10:41:24 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/26 16:57:15 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Adds a new item to the history
**
**	@param list Linked list representing the history
**	@param new New item to add
*/
void	history_add_elem_list(t_hist **list, t_hist *new)
{
	t_hist	*ptr;

	ptr = NULL;
	if (!new || !list)
		return ;
	new->next = *list;
	if (*list)
	{
		ptr = (*list)->prev;
		(*list)->prev = new;
	}
	new->prev = ptr;
	if (ptr)
		ptr->next = new;
	*list = new;
}

/*
**	Create a new item to the history
**
**	@param line Line to add in the item
**	@param new New item to add
*/
t_hist	*history_new_elem_list(char *line, size_t len)
{
	t_hist	*new;

	new = malloc(sizeof(t_hist));
	if (!new)
		return (NULL);
	ft_bzero(new, sizeof(t_hist));
	if (!line)
	{
		new->line = NULL;
		new->len = 0;
	}
	else
	{
		new->line = malloc(len);
		if (!new->line)
			return (NULL);
		ft_memcpy(new->line, line, len);
		new->len = len;
	}
	return (new);
}

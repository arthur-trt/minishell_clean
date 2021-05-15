/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:45:47 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/26 17:00:41 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Free the history and its contents
**
**	@param head Linked list representing the history
*/
void	free_history(t_hist **head)
{
	t_hist	*tmp;
	t_hist	*next;

	if (*head)
	{
		tmp = *head;
		while (tmp)
		{
			next = tmp->next;
			free(tmp->line);
			free(tmp);
			tmp = next;
		}
		*head = NULL;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:28:27 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/27 10:38:50 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Adds a new item to the history
**
**	@param input New item to add
**	@param head Linked list representing the history
*/
void	append_history(char *input, t_hist **head)
{
	size_t	len;

	len = ft_strlen(input);
	if (len < MAX_CMD_LINE)
	{
		history_add_elem_list(
			head,
			history_new_elem_list(input, len + 1)
			);
	}
}

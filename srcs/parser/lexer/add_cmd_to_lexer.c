/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd_to_lexer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:18:14 by atrouill          #+#    #+#             */
/*   Updated: 2021/03/08 10:55:33 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


/*
**	Add link to lexer with parameters
**
**	@param cmd Command to save in the link
**	@param token Key corresponding to the initiator of the command
*/
void	add_cmd_to_lexer(t_lexer **lexer, char *cmd, t_token token)
{
	t_lexer	*tmp;
	t_lexer *new;

	new = malloc(sizeof(t_lexer));
	if (*lexer == NULL)
	{
		*lexer = new;
		tmp = *lexer;
	}
	else
	{
		tmp = *lexer;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		tmp = tmp->next;
	}
	tmp->cmd = clean_cmd(cmd);
	tmp->token = token;
	tmp->next = NULL;
}

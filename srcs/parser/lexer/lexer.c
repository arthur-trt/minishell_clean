/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:59:07 by atrouill          #+#    #+#             */
/*   Updated: 2021/08/25 10:44:31 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Search for the next occurrence of quotes
**
**	@param str String where to look for quotes
**	@param pos Position of the first quotes
**
**	@return Position of the first quotes found
*/
int	continue_while_quote(char *str, int pos)
{
	char	quote;

	quote = str[pos];
	pos++;
	while (str[pos] && str[pos] != quote)
		pos++;
	return (pos);
}

/*
**	Checks if the new command comes from a pipe or a semicolon
**
**	@param str Character string entered by the user
**	@param last_pos Position of the end of the last command.
**
**	@return Token representing pipe or semicolon
*/
t_token	find_previous_token(char *str, int last_pos)
{
	t_token	token;

	token = T_NO;
	if (last_pos == 0)
		token = T_NO;
	else if (str[last_pos] == SEMICOLON)
		token = T_SEMICOLON;
	else if (str[last_pos] == PIPE)
		token = T_PIPE;
	return (token);
}

/*
**	Parse the entered line. Separates commands from pipes and semicolons.
**
**	@param input Character string entered by the user
**
**	@return Chained list containing the various separate commands
*/
t_lexer	*lexer(char *input)
{
	t_lexer	*lexer;
	int		i;
	int		last_pos;

	lexer = NULL;
	i = 0;
	last_pos = 0;
	while (input[i] != '\0')
	{
		if ((input[i] == QUOTE || input[i] == DQUOTE)
			&& ((i > 0 && input[i - 1] != BACKSLAH) || i == 0))
			i = continue_while_quote(input, i);
		else if (input[i] == PIPE || input[i] == SEMICOLON)
		{
			add_cmd_to_lexer(&lexer,
				ft_substr(input, last_pos, i - last_pos),
				find_previous_token(input, last_pos));
			last_pos = i;
		}
		i++;
	}
	add_cmd_to_lexer(&lexer,
		ft_substr(input, last_pos, i - last_pos),
		find_previous_token(input, last_pos));
	return (lexer);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:17:10 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/23 10:21:54 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_check_redirect(int *i, char *s)
{
	char	*redir;

	if (ft_strncmp(s + (*i), "<<", 2) == 0)
	{
		redir = "<<";
		(*i)++;
	}
	else if (ft_strncmp(s + (*i), ">", 1) == 0)
		redir = ">";
	else if (ft_strncmp(s + (*i), ">>", 2) == 0)
	{
		redir = ">>";
		(*i)++;
	}
	else if (ft_strncmp(s + (*i), "<", 1) == 0)
		redir = "<";
	return (ft_strdup(redir));
}

/*
**	Checks current character and applies a function according to it
**
**	@param	command linked list containing parsed commands
**	@param	res buffer string containing the ongoing parsed string
**	@param	s the user's input
**	@param	i the position of the character on s
**	@return r = 0 on success r < 0 if error
*/
int	ft_check_char(t_list *command, char **res, char *s, int *i)
{
	int		r;

	r = 0;
	if (s[(*i)] == '<' || s[(*i)] == '>')
		*res = ft_check_redirect(i, s);
	else if (s[*i] == '\"' && ((*i) > 0 && s[(*i) - 1] != '\\'))
	{
		r = double_checker(s, i, res, command);
		if (r == 1)
			return (0);
		if (r < 0)
			return (r);
	}
	else if (s[*i] == '\'')
		*res = ft_apply(s, i, &ft_single, *res);
	else if (s[*i] == '~' )
		*res = home_tild(*res);
	else
		*res = ft_apply_str(s, i, *res);
	if (!(*res) && !(r))
		return (ft_parse_error(command));
	return (r);
}

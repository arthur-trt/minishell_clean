/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:12:48 by jcueille          #+#    #+#             */
/*   Updated: 2021/04/29 23:36:40 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

extern	t_glob *g_glob;

/*
**	@brief When space is reached, adds *s to the *command linked list
**	
**	@param s string to add
**	@param command linked list on which to add s
**	@return 0 on success negative value if malloc error
*/
int			ft_empty_buffer(char **s, t_list **command)
{
	t_list	*tmp;
	char	*copy;

	if (!(*s))
		return (0);
	if (!(copy = ft_strdup(*s)))
		return (-1);
	if (!(tmp = ft_lstnew(copy)))
		return (-2);
	ft_lstadd_back(command, tmp);
	free(*s);
	*s = NULL;
	return (0);
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
int			ft_check_char(t_list *command, char **res, char *s, int *i)
{
	int		r;

	r = 0;
	if (s[*i] == '\"')
	{
		if ((r = ft_apply_double(s, i, &ft_double, res)))
			return (ft_double_error(r, command, *res));
	}
	else if (s[*i] == '\'')
		*res = ft_apply(s, i, &ft_single, *res);
	else if (s[*i] == '$')
		*res = ft_apply_var(s, i, *res);
	else
		*res = ft_apply(s, i, &ft_string, *res);
	if (!(*res))
		return (ft_parse_error(command));
	return (r);
}

/*
**	Parses the input according to bash standards
**	
**	@param	s the user's input we are going to parse
**	@return command linked list containing parsed commands or NULL if an error occured.
*/
t_list		*ft_parse(char *s)
{
	t_list	*command;
	char	*res;
	int		i;
	int		r;

	r = 0;
	i = -1;
	res = NULL;
	command = NULL;
	while (s[++i])
	{
		if (s[i] != ' ')
		{
			if (ft_check_char(command, &res, s, &i))
				return (NULL);
		}
		else if (s[i] == ' ')
			if (ft_empty_buffer(&res, &command))
				ft_parse_error(command);
	}
	if (res)
		if (ft_empty_buffer(&res, &command))
			ft_parse_error(command);
	return (command);
}

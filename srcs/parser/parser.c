/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:12:48 by jcueille          #+#    #+#             */
/*   Updated: 2021/08/24 16:58:31 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

extern t_glob	*g_glob;

/*
**	@brief When space is reached, adds *s to the *command linked list
**
**	@param s string to add
**	@param command linked list on which to add s
**	@return 0 on success negative value if malloc error
*/
int	ft_empty_buffer(char **s, t_list **command)
{
	t_list	*tmp;
	char	*copy;

	if (!(*s))
		return (0);
	copy = ft_strdup(*s);
	if (copy == NULL)
		return (-1);
	tmp = ft_lstnew(copy);
	if (tmp == NULL)
		return (-2);
	if (g_glob->d_quote == true)
	{
		tmp->d_quote = 1;
		g_glob->d_quote = false;
	}
	ft_lstadd_back(command, tmp);
	free(*s);
	*s = NULL;
	return (0);
}

static int	double_checker(char *s, int *i, char **res, t_list *command)
{
	int	r;

	r = 0;
	if (s[*i + 1] != '\"')
	{	
		r = ft_apply_double(s, i, &ft_double, res);
		if (r != 0)
			return (ft_double_error(r, command, *res));
	}
	else
	{
		(*i) += 1;
		return (1);
	}
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
int	ft_check_char(t_list *command, char **res, char *s, int *i)
{
	int		r;

	r = 0;
	if (*i == 0 && (!(s[*i]) || s[*i] == ' ') && !command)
		ft_command_not_found(command);
	if (s[*i] == '\"')
	{
		r = double_checker(s, i, res, command);
		if (r == 1)
			return (0);
		if (r < 0)
			return (r);
	}
	else if (s[*i] == '\'')
		*res = ft_apply(s, i, &ft_single, *res);
	else if (s[*i] == '$' )
		*res = ft_apply_var(s, i, *res, &r);
	else if (s[*i] == '~' )
		*res = home_tild(*res);
	else
		*res = ft_apply_str(s, i, *res);
	if (!(*res) && !(r))
		return (ft_parse_error(command));
	return (r);
}

/*
**	Parses the input according to bash standards
**
**	@param	s the user's input we are going to parse
**	@return command linked list containing parsed commands
**	or NULL if an error occured.
*/
t_list	*ft_parse(char *s)
{
	t_list	*command;
	char	*res;
	int		i;

	i = 0;
	res = NULL;
	command = NULL;
	while (s[i])
	{
		if (s[i] != ' ')
		{
			if (ft_check_char(command, &res, s, &i))
				return (NULL);
		}
		else if (s[i] == ' ')
			if (ft_empty_buffer(&res, &command))
				ft_parse_error(command);
		i++;
	}
	if (res)
		if (ft_empty_buffer(&res, &command))
			ft_parse_error(command);
	return (command);
}

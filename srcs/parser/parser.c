/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:12:48 by jcueille          #+#    #+#             */
/*   Updated: 2021/10/18 14:51:39 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

extern t_glob	*g_glob;

static void	reinit_glob(void)
{
	g_glob->d_quote = false;
	g_glob->esc = false;
	g_glob->expanded = false;
}

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
		tmp->d_quote = 1;
	if (g_glob->esc == true)
		tmp->esc = 1;
	if (g_glob->expanded == true)
		tmp->expanded = 1;
	reinit_glob();
	ft_lstadd_back(command, tmp);
	free(*s);
	*s = NULL;
	return (0);
}

static int	empty_buff_checker(char *s, char *res, int i)
{
	if (s[i] == ' ' || (res != NULL && ft_ischarset(res[0], "<>"))
		|| ((ft_strlen(s) - 2) >= (size_t)i && ft_ischarset(s[i + 1], "<>")))
		return (1);
	return (0);
}

static t_list	*norm(char **res)
{
	free(*res);
	return (NULL);
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
	char	*tmp;

	i = 0;
	res = NULL;
	command = NULL;
	tmp = expand_var(s);
	printf("Expanded : %s\n", tmp);
	while (tmp != NULL && tmp[i] != '\0')
	{
		if (tmp[i] != ' ')
			if (ft_check_char(command, &res, tmp, &i))
				return (norm(&tmp));
		if (empty_buff_checker(tmp, res, i))
			if (ft_empty_buffer(&res, &command))
				ft_parse_error(command);
		i++;
	}
	if (res)
		if (ft_empty_buffer(&res, &command))
			ft_parse_error(command);
	free(tmp);
	return (command);
}

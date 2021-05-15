/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:15:15 by jcueille          #+#    #+#             */
/*   Updated: 2021/04/24 21:31:38 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

extern t_glob *g_glob;

/*
**	Check if a opened curly bracket has a closing curly bracket
**	
**	@param	s user's input string
**	@param	i the position of the current character on s
**	@return 1 if bracket is closed, 0 if bracket isn't closed
*/
static int	ft_bracket_check(char *s, int i)
{
	while (s[i])
	{
		if (s[i] == '}')
			return (1);
		i++;
	}
	printf("ERROR: BRACKET MISSING\n");
	return (0);
}

static char	*ft_add_space(char **ss, int i, char *tmp)
{
	char	*spaced;
	char	*joined;

	spaced = NULL;
	if (!(spaced = ft_strjoin(ss[i], " ")))
		return (NULL);
	if (tmp)
	{
		joined = ft_strjoin(tmp, spaced);
		free(tmp);
		return (joined);
	}
	return (spaced);
}

static char	*ft_remove_spaces(char *s)
{
	char	**ss;
	char	*tmp;
	char	*res;
	int		i;

	i = -1;
	res = 0;
	tmp = NULL;
	res = NULL;
	ss = ft_split(s, ' ');
	free(s);
	while (ss[++i])
	{
		if (!(tmp) && !(ss[i + 1]))
			res = ft_strdup(ss[i]);
		else if (ss[i + 1])
			tmp = ft_add_space(ss, i, tmp);
		else
			res = ft_strjoin(tmp, ss[i]);
		free(ss[i]);
	}
	free(tmp);
	if (ss)
		free(ss);
	return (res);
}

/*
**	Get the value of a variable
**	
**	@param	name the name of the variable to search
**	@param	i the position of the current character on s
**	@return res the value of the variable or NULL if the variable doesn't exist
*/
char *ft_search_value(char *name)
{
	t_env	*tmp;
	char	*res;

	res = NULL;
	tmp = g_glob->env;
	while (tmp)
	{
		if (!(ft_strcmp(name, tmp->key)))
			res = ft_strdup(tmp->value);
		tmp = tmp->next;
	}
	free(name);
	if (res)
		res = ft_remove_spaces(res);
	return (res);
}

/*
**	Variable expansion
**	
**	@param	s user's input string
**	@param	inc	a counter used to increment i
**	@param	i the position of the current character on s
**	@return res the value of the variable or NULL if the variable doesn't exist
*/
char		*ft_search_var(char *s, int *inc, int *i)
{
	int		j;
	char	*name;
	char	*res;

	(*i)++;
	if (!(s[*i]))
		return (NULL);
	if (s[*i] == '{')
	{
		if (!(ft_bracket_check(s, *i)))
			return (NULL);
		(*inc) = 1;
		(*i)++;
	}
	j = *i;
	if (s[*i] == '?')
		return (ft_itoa(g_glob->ret));
	while (s[*i] && s[*i] != ' ' && s[*i] != '}' && s[*i] != '\"')
		(*i)++;
	if (*i - j == 0)
		return (NULL);
	name = ft_substr(s, j, *i - j);
	res = ft_search_value(name);
	if (s[*i] == '"')
		(*i)--;
	return (res);
}

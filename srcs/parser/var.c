/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:15:15 by jcueille          #+#    #+#             */
/*   Updated: 2021/09/08 12:04:18 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

extern t_glob	*g_glob;

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
	ft_putstrerror("parser", "found an non closing bracket");
	return (0);
}

static char	*ft_add_space(char **ss, int i, char *tmp)
{
	char	*spaced;
	char	*joined;

	spaced = NULL;
	spaced = ft_strjoin(ss[i], " ");
	if (spaced == NULL)
		return (NULL);
	if (tmp)
	{
		joined = ft_strjoin(tmp, spaced);
		free(tmp);
		return (joined);
	}
	return (spaced);
}/*
static char	*ft_remove_spaces(char *s)
{
	char	**ss;
	char	*tmp;
	char	*res;
	int		i;

	i = -1;
	res = NULL;
	tmp = NULL;
	ss = ft_split(s, ' ');
	if (s[0] == ' ')
		tmp = ft_strdup(" ");
	while (ss[++i])
	{
		if (!(tmp) && !(ss[i + 1]))
			tmp = ft_strdup(ss[i]);
		else if (ss[i + 1])
			tmp = ft_add_space(ss, i, tmp);
		else
			res = ft_strjoin_free(tmp, ss[i]);
	}
	free(s);
	if (ss)
		free(ss);
	return (res);
}*/

static char	*ft_remove_spaces(char *s, int f)
{
	char	**ss;
	char	*tmp;
	char	*res;
	int		i;

	i = -1;
	res = NULL;
	tmp = NULL;
	ss = ft_split(s, ' ');
	while (ss[++i])
	{
		if (!(tmp) && !(ss[i + 1]))
			tmp = ft_strdup(ss[i]);
		else if (ss[i + 1])
			tmp = ft_add_space(ss, i, tmp);
		else
			res = ft_strjoin_free(tmp, ss[i]);
	}
	if (ss)
		free(ss);
	if (s[0] == ' ' && !(f))
	{
		tmp = ft_strjoin(" ", res);
		free(res);
		free(s);
		return (tmp);
	}
	free(s);
	return (res);
}

/*
**	Get the value of a variable
**
**	@param	name the name of the variable to search
**	@param	i the position of the current character on s
**	@return res the value of the variable or NULL if the variable doesn't exist
*/
char	*ft_search_value(char *name, int f)
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
	if (name)
		free(name);
	if (res)
		res = ft_remove_spaces(res, f);
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
char	*ft_search_var(char *s, int *i, int f)
{
	int		j;
	char	*res;

	if (!(s[++(*i)]))
		return (NULL);
	if (s[*i] == '{')
	{
		if (!(ft_bracket_check(s, *i)))
			return (NULL);
		(*i)++;
	}
	j = *i;
	if (s[*i] == '?')
		return (ft_itoa(g_glob->ret));
	while (s[*i] && s[*i] != ' ' && s[*i] != '}' && s[*i] != '\"'
		&& s[*i] != '$' && s[*i] != '/' && s[*i] != '=' && s[*i] != '\\')
		(*i)++;
	if (*i - j == 0)
		return (NULL);
	res = ft_search_value(ft_substr(s, j, *i - j), f);
	if (s[*i] == '"' || s[*i] == '\0' || s[*i] == '\'' || s[*i] == '$'
		|| s[*i] == '/' || s[*i] == '=' || s[*i] == '\\')
		(*i)--;
	return (res);
}

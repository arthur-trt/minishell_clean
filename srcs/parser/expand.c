/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 09:50:50 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/20 12:07:20 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

static void	add_char(char **res, char c)
{
	size_t	len;
	char	*tmp;

	if (*res != NULL)
	{
		len = ft_strlen(*res);
		tmp = malloc((len + 2) * sizeof(char));
		ft_bzero(tmp, len + 2);
		ft_strlcpy(tmp, *res, len + 2);
		tmp[len] = c;
		free(*res);
		*res = tmp;
	}
}

static void	replace_last_ret(char **res, size_t *i, char *user_input)
{
	int		j;
	char	*tmp;

	while (user_input[(*i)] == '$' || user_input[(*i)] == '?')
		(*i)++;
	tmp = ft_itoa(g_glob->ret);
	j = 0;
	while (tmp[j] != '\0')
	{
		add_char(res, tmp[j]);
		j++;
	}
	free(tmp);
}

static void	dumb_norm(char **res, size_t *i, size_t start, char *user_input)
{
	char	*tmp;
	char	*var;

	tmp = ft_substr(user_input, start, (*i) - start);
	var = search_env(tmp);
	free(tmp);
	if (var != NULL)
	{
		tmp = ft_strdup(var);
		ft_strjoin_gnl(res, tmp);
		free(tmp);
	}
}

static bool	replace_var(char *user_input, char **res, size_t *i)
{
	bool	flag;
	size_t	start;

	flag = true;
	if (user_input[*i] == '$')
		(*i)++;
	if (user_input[*i] == '{')
	{
		flag = false;
		(*i)++;
	}
	start = *i;
	while (user_input[*i] != '\0' && ft_isalnum(user_input[*i]))
		(*i)++;
	dumb_norm(res, i, start, user_input);
	if (user_input[(*i)] == '}')
	{
		flag = !flag;
		(*i)++;
	}
	return (flag);
}

char	*expand_var(char *user_input)
{
	char	*res;
	size_t	i;
	bool	flag;

	i = 0;
	res = ft_strdup("");
	flag = true;
	while (user_input && user_input[i] != '\0')
	{
		if (user_input[i] == '\'')
			flag = !flag;
		if (flag && user_input[i] == '$'
			&& (user_input[i + 1] != '\0' && user_input[i + 1] == '?'))
			replace_last_ret(&res, &i, user_input);
		if (flag && user_input[i] == '$'
			&& !(i > 0 && user_input[i - 1] == '\\')
			&& (replace_var(user_input, &res, &i) == false))
		{
			ft_putstrerror(NULL, "bad substitution");
			return (NULL);
		}
		if (user_input[i] != '\0')
			add_char(&res, user_input[i++]);
	}
	return (res);
}

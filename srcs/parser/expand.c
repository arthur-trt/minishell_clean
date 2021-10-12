/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 09:50:50 by atrouill          #+#    #+#             */
/*   Updated: 2021/10/12 14:42:41 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

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
		tmp = quote_in_var(var);
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

void check_flag(char *flag, char c)
{
	if (!(*flag))
		(*flag) = c;
	else if (*flag == c)
		(*flag) = '\0';
}

static char	*i_hate_norm(char *user_input, char *flag, size_t i)
{
	char	*res;

	res = ft_strdup("");
	while (user_input && user_input[i] != '\0')
	{
		if (user_input[i] == '\'' || user_input[i] == '\"')
			check_flag(flag, user_input[i]);
		if (*flag == '\"' && user_input[i] == '$'
			&& (user_input[i + 1] != '\0' && user_input[i + 1] == '?'))
			replace_last_ret(&res, &i, user_input);
		else if ((*flag == '\0' || *flag=='\"') && user_input[i] == '$'
			&& !(i > 0 && user_input[i - 1] == '\\')
			&& (user_input[i + 1] != '\0'
				&& (ft_isalnum(user_input[i + 1]) || user_input[i + 1] == '{')))
		{
			if (replace_var(user_input, &res, &i) == false)
			{
				ft_putstrerror(NULL, "bad substitution");
				return (NULL);
			}
		}
		else if (user_input[i] != '\0')
			add_char(&res, user_input[i++]);
	}
	return (res);
}

char	*expand_var(char *user_input)
{
	size_t	i;
	char	flag;

	i = 0;
	flag = '\0';
	return (i_hate_norm(user_input, &flag, i));
}

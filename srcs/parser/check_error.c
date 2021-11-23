/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 15:28:37 by atrouill          #+#    #+#             */
/*   Updated: 2021/11/23 10:12:19 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*remove_space(char *user_input)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = malloc((ft_strlen(user_input) + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_bzero(res, ft_strlen(user_input) + 1);
	while (user_input[i])
	{
		if (user_input[i] != ' ')
		{
			res[j] = user_input[i];
			j++;
		}
		i++;
	}
	return (res);
}

static bool	valid_token_input(char *user_input)
{
	bool	ret;
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = remove_space(user_input);
	ret = true;
	if (tmp[0] == PIPE || tmp[0] == SEMICOLON)
		ret = false;
	while (ret && tmp[i])
	{
		if (tmp[i] == PIPE || tmp[i] == SEMICOLON)
		{
			if (tmp[i + 1] == PIPE || tmp[i + 1] == SEMICOLON || tmp[i + 1] == '\0')
				ret = false;
		}
		if (tmp[i] == '\"' || tmp[i] == '\'')
			skip_quotes(tmp, tmp[i], &i);
		i++;
	}
	free(tmp);
	return (ret);
}

static bool	is_redirect_char(char *s, size_t *i)
{
	if (s[(*i)] == '<' || s[(*i)] == '>')
	{
		if (s[(*i) + 1] != '\0')
		{
			(*i)++;
			if (s[(*i)] == '<' || s[(*i)] == '>')
				(*i)++;
			return (true);
		}
	}
	return (false);
}

static bool	valid_redirect_input(char *user_input)
{
	size_t	i;
	char	c;

	i = 0;
	while (i < ft_strlen(user_input))
	{
		if (is_redirect_char(user_input, &i))
		{
			while (user_input[i] == ' ')
				i++;
			c = user_input[i];
			if (c == SEMICOLON || c == PIPE || c == '>' || c == '<')
				return (false);
		}
		if (user_input[i] == '\"' || user_input[i] == '\'')
			skip_quotes(user_input, user_input[i], &i);
		i++;
	}
	return (true);
}

bool	check_error(char *user_input)
{
	if (!valid_token_input(user_input) || !valid_redirect_input(user_input)
		|| !valid_heredocs(user_input))
		return (false);
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 09:50:50 by atrouill          #+#    #+#             */
/*   Updated: 2021/10/19 11:15:56 by atrouill         ###   ########.fr       */
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

static void	check_flag(char *flag, char c)
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
		if ((*flag == '\0' || *flag == '\"') && user_input[i] == '$'
			&& (user_input[i + 1] != '\0' && user_input[i + 1] == '?'))
			replace_last_ret(&res, &i, user_input);
		else if ((*flag == '\0' || *flag == '\"') && user_input[i] == '$'
			&& !(i > 0 && user_input[i - 1] == '\\')
			&& (user_input[i + 1] != '\0'
				&& (ft_isalnum(user_input[i + 1]) || user_input[i + 1] == '{')))
		{
			if (replace_var_expand(user_input, &res, &i) == false)
			{
				free(res);
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
	char	*res;

	i = 0;
	flag = '\0';
	res = i_hate_norm(user_input, &flag, i);
	if (res == NULL)
	{
		ft_putstrerror(NULL, "bad substitution");
		return (NULL);
	}
	return (res);
}

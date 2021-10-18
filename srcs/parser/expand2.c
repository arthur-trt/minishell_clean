/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:59:36 by atrouill          #+#    #+#             */
/*   Updated: 2021/10/14 10:57:57 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

bool	replace_var_expand(char *user_input, char **res, size_t *i)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 09:50:50 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/10 15:05:02 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_char(char **res, char c)
{
	size_t	len;
	char	*tmp;

	len = ft_strlen(*res);
	tmp = malloc((len + 2) * sizeof(char));
	ft_strlcpy(tmp, *res, len + 2);
	tmp[len] = c;
	tmp[len + 1] = '\0';
	free(*res);
	*res = tmp;
}

static void	replace_var(char *user_input, char **res, int *i)
{
	int		start;
	char	*tmp;
	char	*var;

	start = *i;
	while (user_input[*i] != '\0' && ft_isalnum(user_input[*i]))
	{
		(*i)++;
	}
	tmp = ft_substr(user_input, start, *i);
	var = search_env(tmp);
	free(tmp);
	if (var != NULL)
	{
		tmp = ft_strdup(var);
		ft_strjoin_gnl(res, tmp);
		free(tmp);
	}
}

char	*expand_var(char *user_input)
{
	char	*res;
	int		i;

	i = 0;
	res = ft_strdup("");
	while (user_input && user_input[i] != '\0')
	{
		if (user_input[i] == '$'
			&& (i > 1 && user_input[i - 1] != '\\'))
			replace_var(user_input, &res, &i);
		else if (user_input[i] == '\\')
			i++;
		add_char(&res, user_input[i]);
		i++;
	}
	free(user_input);
	return (res);
}

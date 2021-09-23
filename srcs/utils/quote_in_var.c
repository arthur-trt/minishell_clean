/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_in_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 10:09:18 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/23 10:17:57 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*quote_in_var(char *var)
{
	int		i;
	char	*res;

	i = 0;
	if (ft_strrchr(var, '\"') == NULL && ft_strrchr(var, '\'') == NULL)
		return (ft_strdup(var));
	res = ft_strdup("");
	while (var[i] != '\0')
	{
		if (var[i] == '\"' || var[i] == '\'')
			add_char(&res, '\\');
		if (var[i] == '\"')
			add_char(&res, '\"');
		else if (var[i] == '\'')
			add_char(&res, '\'');
		else
			add_char(&res, var[i]);
		i++;
	}
	return (res);
}

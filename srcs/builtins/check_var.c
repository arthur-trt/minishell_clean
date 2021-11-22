/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:26:19 by atrouill          #+#    #+#             */
/*   Updated: 2021/11/22 11:50:52 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*obtain_value_var(char *user_input)
{
	int		i;
	char	*res;

	i = 0;
	while (user_input[i] != '\0' && user_input[i] != '=')
		i++;
	if (user_input[i] == '\0' || user_input[i + 1] == '\0')
		return (NULL);
	res = ft_substr(user_input, i + 1, ft_strlen(user_input));
	return (res);
}

char	*obtain_key_var(char *user_input)
{
	int		i;
	char	*res;

	i = 0;
	while (user_input[i] != '\0' && user_input[i] != '=')
		i++;
	if (user_input[i] == '\0')
		return (ft_strdup(user_input));
	res = ft_substr(user_input, 0, i);
	return (res);
}

/*
**	This function verify that the variable name follow the bash syntax
**	[a-zA-Z_]+[a-zA-Z0-9_]*
**
**	@param var Var name to test
**
**	@return True if correct, false otherwise
*/
bool	check_var_name(char *var)
{
	int	i;

	i = 1;
	if (ft_isalpha(var[0]) == false)
		return (false);
	while (var && var[i])
	{
		if (ft_isalnum(var[i]) == false && var[i] != '_')
			return (false);
		i++;
	}
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:26:19 by atrouill          #+#    #+#             */
/*   Updated: 2021/11/19 15:48:34 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

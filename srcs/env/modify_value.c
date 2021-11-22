/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 22:30:11 by jcueille          #+#    #+#             */
/*   Updated: 2021/11/22 14:24:08 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

extern t_glob	*g_glob;

/*
**	Change the value of a key in the environment
**
**	@param key Key to modify
**	@param new_value New value for the key
**
**	@return 0 if done, -1 in case of error
*/
int	ft_modify_value(char *key, char *new_value)
{
	t_env	*tmp;

	tmp = g_glob->env;
	while (tmp)
	{
		if (!(ft_strcmp(key, tmp->key)))
		{
			debug("key : [%s]", key);
			debug("tmp->key : [%s]", tmp->key);
			if (tmp->value)
				free(tmp->value);
			tmp->value = ft_strdup(new_value);
			if (tmp->value == NULL)
				return (-1);
		}
		tmp = tmp->next;
	}
	return (0);
}

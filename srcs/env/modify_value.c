/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 22:30:11 by jcueille          #+#    #+#             */
/*   Updated: 2021/05/02 20:36:50 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

extern t_glob *g_glob;

int		ft_modify_value(char *key, char *new_value)
{
	t_env	*tmp;

	tmp = g_glob->env;
	while (tmp)
	{
		if (!(ft_strcmp(key, tmp->key)))
		{
			if (tmp->value)
				free(tmp->value);
			if (!(tmp->value = ft_strdup(new_value)))
				return (-1);
		}
		tmp = tmp->next;
	}
	return (0);
}
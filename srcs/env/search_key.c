/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:42:56 by atrouill          #+#    #+#             */
/*   Updated: 2021/02/12 14:49:55 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*search_env(t_env env, char *key)
{
	t_env	tmp;

	tmp = env;
	while(tmp.next != NULL)
	{
		if (!ft_strncmp(tmp.key, key, ft_strlen(key)))
		{
			return (tmp.value);
		}
		tmp = *(tmp.next);
	}
	return NULL;
}

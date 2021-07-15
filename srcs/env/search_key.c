/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:42:56 by atrouill          #+#    #+#             */
/*   Updated: 2021/07/15 13:44:35 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

/*
**	Search for the value of a key in the environment
**
**	@param Key whose value must be sought
**
**	@return The value if found, NULL otherwise
*/
char	*search_env(char *key)
{
	t_env	tmp;

	if (g_glob->env != NULL)
	{
		tmp = *(g_glob->env);
		while (tmp.next != NULL)
		{
			if (!ft_strncmp(tmp.key, key, ft_strlen(key)))
			{
				return (tmp.value);
			}
			tmp = *(tmp.next);
		}
	}
	return (NULL);
}

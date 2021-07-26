/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:48:56 by atrouill          #+#    #+#             */
/*   Updated: 2021/07/26 15:05:07 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

/*
**	Free global variable
*/
void	free_glob(void)
{
	t_env	*tmp;
	t_env	*next;

	if (g_glob && g_glob->env)
	{
		tmp = g_glob->env;
		while (tmp)
		{
			next = tmp->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
			tmp = next;
		}
		g_glob->env = NULL;
	}
	if (g_glob)
	{
		free(g_glob);
		g_glob = NULL;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:48:56 by atrouill          #+#    #+#             */
/*   Updated: 2021/05/02 18:06:23 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob *g_glob;

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

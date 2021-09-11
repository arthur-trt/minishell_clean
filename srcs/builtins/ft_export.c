/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:38:43 by jcueille          #+#    #+#             */
/*   Updated: 2021/09/11 18:43:18 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

static void	no_args(void)
{
	t_env	*env;

	env = g_glob->env;
	while (env)
	{
		printf("export %s=%s\n", env->key, env->value);
		env = env->next;
	}
}

int	ft_export(t_list *cmd)
{
	t_list	*tmp;
	int		r;

	tmp = NULL;
	if (cmd != NULL)
		tmp = cmd->next;
	if (tmp)
	{
		r = export_loop(tmp);
		if (r < 0)
			return (r);
	}
	else
		no_args();
	return (0);
}

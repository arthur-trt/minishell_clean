/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:50:12 by atrouill          #+#    #+#             */
/*   Updated: 2021/05/16 15:52:06 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

void	print_env(void)
{
	t_env	*tmp;

	tmp = g_glob->env;
	while (tmp)
	{
		printf("key : %s\nvalue : %s\n\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}

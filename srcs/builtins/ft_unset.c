/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:07:52 by jcueille          #+#    #+#             */
/*   Updated: 2021/11/19 15:46:58 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

static int	ft_delfirst_maillon(t_env *env)
{
	free(env->key);
	free(env->value);
	g_glob->env = env->next;
	free(env);
	return (0);
}

int	ft_del_maillon(t_env *env, t_env *buff)
{
	t_env	*tmp;

	tmp = env->next;
	free(env->key);
	free(env->value);
	free(env);
	env = tmp;
	buff->next = env;
	return (0);
}

int	ft_unset_launcher(char *s)
{
	t_env	*tmp;
	t_env	*tmp2;

	tmp = g_glob->env;
	tmp2 = g_glob->env;
	if (tmp && !(ft_strcmp(tmp->key, s)))
	{
		ft_delfirst_maillon(tmp);
		return (0);
	}
	tmp = tmp->next;
	while (tmp)
	{
		if (!(ft_strcmp(tmp->key, s)))
		{
			ft_del_maillon(tmp, tmp2);
			return (0);
		}
		tmp2 = tmp;
		tmp = tmp->next;
	}
	return (0);
}

int	ft_unset(t_list *cmd)
{
	t_list	*tmp;
	//int		r;

	tmp = cmd->next;
	while (tmp)
	{
		if (check_var_name(tmp->content) == false)
		{
			ft_putstrerrorparam("unset", tmp->content,
				"not a valid identifier");
			return (1);
		}
		ft_unset_launcher(tmp->content);
		tmp = tmp->next;
	}
	return (0);
}

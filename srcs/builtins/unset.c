/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:07:52 by jcueille          #+#    #+#             */
/*   Updated: 2021/04/19 20:46:06 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

extern t_glob *g_glob;

static int	ft_delfirst_maillon(t_env *env)
{
	free(env->key);
	free(env->value);
	g_glob->env = env->next;
	free(env);
	return (0);
}

int			ft_del_maillon(t_env *env, t_env *buff)
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

int			ft_unset_launcher(char *s)
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

int		ft_check_varname(char *s)
{
	int i;

	i = 0;
	if (!(ft_isalpha(s[0]) && s[0] != '_'))
	{
		if (s[0] == '-')
			printf("Error: bad option: %s\n", s);
		else
				printf("Error: bad variable name: %s\n", s);	
		return (-1);
	}
	while (s[++i])
	{
		if (!(ft_isalnum(s[i])) && s[i] != '_')
		{	
			printf("Error: bad variable name: %s\n", s);
			return (-2);
		}
	}
	return (0);
}

int			ft_unset(t_list *cmd)
{
	t_list	*tmp;
	int		r;

	tmp = cmd->next;
	while (tmp)
	{
		if ((r = ft_check_varname(cmd->content)))
			return (r);
		ft_unset_launcher(tmp->content);
		tmp = tmp->next;
	}
	return (0);
}
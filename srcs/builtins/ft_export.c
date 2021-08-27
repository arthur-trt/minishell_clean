/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:38:43 by jcueille          #+#    #+#             */
/*   Updated: 2021/08/18 19:02:53 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

int	ft_get_value(char *s, int *i, char **value)
{
	int	k;

	(*i)++;
	k = *i;
	if (s[*i])
	{
		while (s[*i])
			(*i)++;
	}
	*value = ft_substr(s, k, *i - k);
	if (!(*value))
		return (-1);
	return (0);
}

int	ft_get_keyvalue(char *s, char **key, char **value)
{
	int	i;

	*key = NULL;
	*value = NULL;
	i = 0;
	while (s[i] && s[i] != '=')
	{
		if (!(ft_isalnum(s[i]) && s[i] != '_'))
			return (-2);
		i++;
	}
	if (s[i] == '=')
	{
		*key = ft_substr(s, 0, i);
		if (!(*key))
			return (-1);
		if (ft_get_value(s, &i, value))
			return (-1);
	}
	else
		return (1);
	return (0);
}

int	ft_addmaillon(char *key, char *value)
{
	t_env	*env;

	if (key)
	{
		env = malloc(sizeof(t_env));
		if (!(env))
			return (-1);
		env->key = key;
		env->value = value;
		env->next = g_glob->env;
		g_glob->env = env;
	}
	return (0);
}

int	replace_var(char *key, char *value)
{
	t_env	*env;

	env = g_glob->env;
	while (env)
	{
		if (!(ft_strcmp(key, env->key)))
		{
			free(env->value);
			env->value = value;
			return (1);
		}
		env = env->next;
	}
	return (0);
}

int	ft_export(t_list *cmd)
{
	t_list	*tmp;
	char	*key;
	char	*value;
	int		r;

	tmp = NULL;
	if (cmd != NULL)
		tmp = cmd->next;
	if (tmp)
	{
		while (tmp)
		{
			r = ft_get_keyvalue(tmp->content, &key, &value);
			if (r < 0)
				return (-1);
			if (r == 1)
				break ;
			if (key && ft_check_varname(key))
				return (-2);
			if (!(replace_var(key, value)))
			{
				if (ft_addmaillon(key, value))
					return (-3);
			}
			tmp = tmp->next;
		}
	}
	else
		ft_env();
	return (0);
}

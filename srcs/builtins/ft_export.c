/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:55:31 by atrouill          #+#    #+#             */
/*   Updated: 2021/11/22 18:56:01 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

static void	add_to_env(char *key, char *value)
{
	t_env	*env;

	if (search_env(key) != NULL)
	{
		ft_modify_value(key, value);
	}
	else
	{
		if (key)
		{
			env = malloc(sizeof(t_env));
			if (env)
			{
				env->key = ft_strdup(key);
				if (value != NULL)
					env->value = ft_strdup(value);
				else
					env->value = ft_strdup("");
				env->next = g_glob->env;
				g_glob->env = env;
			}
		}
	}
}

int	ft_export(t_list *cmd)
{
	t_list	*tmp;
	int		ret;
	char	*key;
	char	*value;

	tmp = cmd->next;
	ret = 0;
	while (tmp)
	{
		key = obtain_key_var(tmp->content);
		value = obtain_value_var(tmp->content);
		if (check_var_name(key) == false)
		{
			ft_putstrerrorparam("export", tmp->content,
				"not a valid identifier");
			ret = 2;
		}
		else if (ft_strcontain(tmp->content, '='))
			add_to_env(key, value);
		free(key);
		free(value);
		tmp = tmp->next;
	}
	return (ret);
}

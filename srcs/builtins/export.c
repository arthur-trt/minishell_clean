/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:38:43 by jcueille          #+#    #+#             */
/*   Updated: 2021/04/24 21:30:50 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include "../../inc/sh_parser.h"
#include "../../inc/sh_builtins.h"

//extern t_glob *g_glob;
t_glob *g_glob;

int			ft_get_value(char *s, int *i, char **value)
{
	int	k;

	(*i)++;
	k = *i;
	if (s[*i])
	{
		while (s[*i])
			(*i)++;
	}
	if (!(*value = ft_substr(s, k, *i - k)))
		return (-1);
	return (0);
}

int			ft_get_keyvalue(char *s, char **key, char **value)
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
		if (!(*key = ft_substr(s, 0, i)))
			return (-1);
		if(ft_get_value(s, &i, value))
			return (-1);
	}
	return (0);
}

int			ft_addmaillon(char *key, char *value)
{
	t_env	*env;

	if (!(env = malloc(sizeof(t_env *))))
		return (-1);
	env->key = key;
	env->value = value;
	env->next = g_glob->env;
	g_glob->env = env;
	return (0);
}

int			ft_export(t_list *cmd)
{
	t_list	*tmp;
	char	*key;
	char	*value;
	int		r;

	tmp = NULL;
	if (cmd != NULL)
		tmp = cmd->next;
	r = 0;
	if (tmp)
	{
		while (tmp)
		{
			if ((r = ft_get_keyvalue(tmp->content, &key, &value)))
				return (r);
			if (key && (r = ft_check_varname(key)))
				return (r);
			if ((r = ft_addmaillon(key, value)))
				return (r);
			tmp = tmp->next;
		}
	}
	else
		ft_env();
	return (0);
}

void		ft_new_env(void)
{
	t_env	*tmp;

	g_glob->env = malloc(sizeof(t_env));
	g_glob->env->key = ft_strdup("VAR");
	g_glob->env->value = ft_strdup("VALUE");
	tmp = malloc(sizeof(t_env));
	g_glob->env->next = tmp;
	tmp->key = ft_strdup("VARZ");
	tmp->value = ft_strdup("VA     LUW");
	tmp->next = NULL;
}

void		ft_free_env(void)
{
	t_env	*tmp;

	while (g_glob->env)
	{
		tmp = g_glob->env->next;
		free(g_glob->env->key);
		free(g_glob->env->value);
		free(g_glob->env);
		g_glob->env = tmp;
	}
}

void ft_newcmd(t_list **cmd)
{
	char *s;
	t_list *tmp;

	s = ft_strdup("export");
	tmp = ft_lstnew(s);
	ft_lstadd_back(cmd, tmp);
	s = ft_strdup("VALUE=name");
	tmp = ft_lstnew(s);
	ft_lstadd_back(cmd, tmp);
	s = ft_strdup("2lu=n");
	tmp = ft_lstnew(s);
	ft_lstadd_back(cmd, tmp);

}

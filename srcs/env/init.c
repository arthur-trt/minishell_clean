/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:48:45 by atrouill          #+#    #+#             */
/*   Updated: 2021/06/04 12:01:54 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

static void	init_env_elem(t_env *env)
{
	env->key = NULL;
	env->value = NULL;
	env->next = NULL;
}

void	add_env(char *key, char *value)
{
	t_env	*new;
	t_env	*tmp;

	new = malloc(sizeof(t_env));
	init_env_elem(new);
	if (new == NULL)
		exit(EXIT_FAILURE);
	new->key = ft_strdup(key);
	if (value == NULL)
		new->value = ft_strdup("");
	else
		new->value = ft_strdup(value);
	if ((g_glob->env) == NULL)
	{
		new->next = NULL;
		g_glob->env = new;
	}
	else
	{
		tmp = g_glob->env;
		while (tmp->next != NULL)
			tmp = tmp->next;
		new->next = tmp->next;
		tmp->next = new;
	}
}

static void	construct_env(char **environ)
{
	char	**tmp;
	int		i;

	i = 0;
	while (environ[i])
	{
		tmp = ft_split_env(environ[i]);
		add_env(tmp[0], tmp[1]);
		free(tmp[0]);
		free(tmp[1]);
		free(tmp);
		i++;
	}
}

/*
**	Creates basic environment if env = NULL
**
**	@return 0 on success -1 if malloc error
*/
static int	ft_empty_env(void)
{
	char	*cwd;
	char	buf[4096];

	cwd = getcwd(buf, 4096);
	add_env("PWD", cwd);
	add_env("SHLVL", ft_strdup("0"));
	return (0);
}

/*
**	malloc space for global variable
**
**	@return 0 on success
*/
int	ft_init_gobal(void)
{
	extern char		**environ;

	g_glob = malloc(sizeof(t_glob));
	g_glob->env = NULL;
	if (environ)
		construct_env(environ);
	else
		ft_empty_env();
	g_glob->ret = 0;
	history_path();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:48:45 by atrouill          #+#    #+#             */
/*   Updated: 2021/05/15 15:05:40 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern	t_glob *g_glob;
extern char **environ;


void	init_env_elem(t_env *env)
{
	env->key = NULL;
	env->value = NULL;
	env->next = NULL;
}

void	add_env(char *key, char *value)
{
	t_env	*new;
	t_env	*tmp;

	if (!(new = ft_malloc(sizeof(t_env))))
		exit(EXIT_FAILURE);
	init_env_elem(new);
	new->key = ft_strdup(key);
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

static void	construct_env(void)
{
	char	**tmp;
	int		i;

	i = 0;
	while (environ[i])
	{
		tmp = ft_split(environ[i], '=');
		//printf("%s = %s", tmp[0], tmp[1]);
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
static int ft_empty_env(void)
{
	char *cwd;
	char	buf[4096];

	cwd = getcwd(buf, 4096);
	add_env("PWD", cwd);
	add_env("SHLVL", ft_strdup("0"));
	return (0);
}

/*
** malloc space for global variable
**	@return 0 on success 
*/
int	ft_init_gobal(void)
{
	
	g_glob = malloc(sizeof(t_glob));
	g_glob->env = NULL;
	if (environ)
		construct_env();
	else
		ft_empty_env();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:15:26 by jcueille          #+#    #+#             */
/*   Updated: 2021/05/24 13:57:49 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

extern t_glob *g_glob;

int				ft_exec_path(t_list *cmds)
{
	char		*filename;
	char		*execname;
	char		**path;
	int			i;
	struct stat file;

	i = -1;
	if (cmds->content[0] == '>' || cmds->content[0] == '/')
		filename = cmds->content;
	else
	{
		execname = ft_strjoin("/", cmds->content);
		path = ft_split(cmds->content, ':');
		while (path[++i])
		{
			filename = ft_strjoin(path[i], execname);
			
		}
	}
}

/*
***	Checks if the command is a builtin
***
*** @param the cmds linked list containing the command
*/
int			is_builtin(char *s)
{
	int		r;

	if (!(ft_strcmp("echo", s)))
		r = ft_echo;
	else if (!(ft_strcmp("pwd", s)))
		r = ft_pwd;
	else if (!(ft_strcmp("env", s)))
		r = ft_env;
	else if (!(ft_strcmp("export", s)))
		r = ft_export;
	else if (!(ft_strcmp("unset", s)))
		r = ft_unset;
	//if (!(ft_strcmp("exit", cmds->content)))
		// r = ft_exit;
	// if (!(ft_strcmp("cd", cmds->content)))
		// r = ft_cd;
	else
		return (0);
	return (r);
}

char		*env_concat(t_env *tmp)
{
	char	*res;
	int		i;
	int		j;

	i = ft_strlen(tmp->key);
	j = ft_strlen(tmp->value);
	if (!(res = malloc(j + i + 2)))
		return (NULL);
	i = -1;
	j = 0;
	while (tmp->key[++i])
	{
		res[j] = tmp->key[i];
		j++;
	}
	res[j] = '=';
	j++;
	i = -1;
	while (tmp->value[++i])
	{
		res[j] = tmp->value[i];
		j++;
	}
	res[j] = '\0';
	return (res);
}

char		**argv_exec_creator(t_list *cmds)
{
	char	**res;
	t_list	*tmp;
	int		i;

	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	if (!(res = malloc(sizeof(char*) * i + 1)))
		return (NULL);
	i = 0;
	tmp = cmds;
	while (tmp)
	{
		res[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
	res[i] = NULL;
	return (res);
}


/*
*** Creates a char** environment for the execve function
*** @return a char** containing the environment
*/
char		**env_exec_creator(void)
{
	char	**envp;
	t_env	*tmp;
	int		i;

	i = 0;
	tmp = g_glob->env;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	tmp = g_glob->env;
	if (!(envp = malloc(sizeof(char *) * i + 1)))
		return (NULL);
	i = 0;
	while (tmp)
	{
		if (!(envp[i] = env_concat(tmp)))
			return (NULL);
		i++;
		tmp = tmp->next;
	}
	envp[i] = NULL;
	return (envp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:15:26 by jcueille          #+#    #+#             */
/*   Updated: 2021/05/30 15:04:49 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob *g_glob;

/*
***	Checks if the command is a builtin
***
*** @param the cmds linked list containing the command
*/
int			is_builtin(t_list *cmds)
{
	int		r;
	t_list	*tmp;

	r = 0;
	tmp = copycmds(cmds);
	if (!(ft_strcmp("echo", cmds->content)))
		r = ft_echo(tmp);
	else if (!(ft_strcmp("pwd", cmds->content)))
		r = ft_pwd();
	else if (!(ft_strcmp("env", cmds->content)))
		r = ft_env();
	else if (!(ft_strcmp("export", cmds->content)))
		r = ft_export(tmp);
	else if (!(ft_strcmp("unset", cmds->content)))
		r = ft_unset(tmp);
	//if (!(ft_strcmp("exit", cmds->content)))
		// r = ft_exit;
	// if (!(ft_strcmp("cd", cmds->content)))
		// r = ft_cd;
	else
		r = exec_path(cmds);
	if (r != 0)
		ft_putstr_fd("Error executing builtin.\n", 2);
	free_list(tmp);
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


int			word_checker(t_list *tmp, char **s)
{
	int		i;

	i = 0;
	while (tmp->content[i])
	{
		if (ft_ischarset(tmp->content[i], "<>"))
		{
			if (i == 0)
				*s = NULL;//ft_strdup("");
			*s = ft_substr(tmp->content, 0, i - 1);
			return (1);
		}
		i++;
	}
	*s = tmp->content;
	return (0);
}
/*
*** Puts all the args in a single char** to send to execve
*** @return a char** containing all the arguments
*/
char		**argv_exec_creator(t_list *cmds)
{
	char	**res;
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = cmds;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	if (!(res = malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = 0;
	tmp = cmds;
	while (tmp)
	{
		if (word_checker(tmp, &res[i]))
		{
			i++;
			break ;
		}
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

	i = 1;
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

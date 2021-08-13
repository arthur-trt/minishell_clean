/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 11:42:26 by jcueille          #+#    #+#             */
/*   Updated: 2021/08/13 14:37:40 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

extern t_glob	*g_glob;

int	word_checker_bis(t_list *tmp, char **s)
{
	int		i;

	i = 0;
	while ((char)&tmp->content[i])
	{
		if (ft_ischarset((char)&tmp->content[i], "<>"))
		{
			if (i == 0)
				*s = NULL;
			else
				*s = ft_substr(tmp->content, 0, i - 1);
			return (1);
		}
		i++;
	}
	*s = tmp->content;
	return (0);
}

/*
*** Creates a char** environment for the execve function
*** @return a char** containing the environment
*/
char	**env_exec_creator(void)
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
	envp = malloc(sizeof(char *) * i + 1);
	if (!(envp))
		return (NULL);
	i = -1;
	while (tmp)
	{
		envp[++i] = env_concat(tmp);
		if (!(envp[i]))
			return (NULL);
		tmp = tmp->next;
	}
	envp[i] = NULL;
	return (envp);
}

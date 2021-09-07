/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 11:42:26 by jcueille          #+#    #+#             */
/*   Updated: 2021/09/07 16:09:44 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

extern t_glob	*g_glob;

bool	ft_ischarset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (true);
		i++;
	}
	return (false);
}

int	word_checker_bis(t_list *tmp, char **s)
{
	int		i;

	i = 0;
	while (tmp->content[i])
	{
		if (ft_ischarset(tmp->content[i], "<>"))
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

/*
***	Gets the file name for the redirection
*** @param char*s the string containing the filename we want to parse
*** @param int*i our current position on the string
*** @return The char *filename if present or NULL if no filename is specified.
*/
char	*get_file_name(char *s, int *i)
{
	int		j;
	char	*filename;

	filename = NULL;
	while (s[*i] == ' ')
		(*i)++;
	j = *i;
	while (s[j] && (ft_isalnum(s[j]) || s[j] == '_'
			|| s[j] == '-' || s[j] == '.' || s[j] == ' '))
		j++;
	if (*i != j)
		filename = ft_substr(s, *i, j - *i);
	return (filename);
}

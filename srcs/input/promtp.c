/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   promtp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:16:47 by atrouill          #+#    #+#             */
/*   Updated: 2021/07/26 14:43:29 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


static char	*construct_username(void)
{
	char	*username;

	username = search_env("USER");
	if (username == NULL)
		username = "user42";
	return (username);
}

static char	*construct_path(char *cwd)
{
	char	*path;
	char	*path_tmp;
	char	*home;

	path = ft_strdup(cwd);
	home = search_env("HOME");
	if (home != NULL && ft_strncmp(cwd, home, ft_strlen(home)) == 0)
	{
		path_tmp = ft_substr(path, ft_strlen(home),
				ft_strlen(path) - ft_strlen(home));
		path = ft_realloc(path, sizeof(char) * (1 + ft_strlen(path_tmp) + 1));
		ft_bzero(path, (1 + ft_strlen(path_tmp) + 1));
		path[0] = '~';
		ft_strlcat(path, path_tmp, (1 + ft_strlen(path_tmp) + 1));
		free(path_tmp);
	}
	return (path);
}

/*
**	Builds the prompt according to the user and the path
**
**	@return String with the prompt
*/
char	*ft_prompt(void)
{
	char	cwd_buffer[MAX_CMD_LINE];
	char	*cwd;
	char	prompt[MAX_CMD_LINE];
	char	*path;

	ft_bzero(cwd_buffer, MAX_CMD_LINE);
	ft_bzero(prompt, MAX_CMD_LINE);
	cwd = getcwd(cwd_buffer, MAX_CMD_LINE);
	ft_strlcat(prompt, "\033[1;32m", MAX_CMD_LINE);
	ft_strlcat(prompt, construct_username(), MAX_CMD_LINE);
	ft_strlcat(prompt, "@minishell\033[0m:\033[1;94m", MAX_CMD_LINE);
	path = construct_path(cwd);
	ft_strlcat(prompt, path, MAX_CMD_LINE);
	free(path);
	ft_strlcat(prompt, "\033[0m$ ", MAX_CMD_LINE);
	return (ft_strdup(prompt));
}

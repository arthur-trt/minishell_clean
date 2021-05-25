/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 13:19:48 by jcueille          #+#    #+#             */
/*   Updated: 2021/05/16 15:53:17 by atrouill         ###   ########.fr       */
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

static char *construct_path(char *cwd)
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
		path = realloc(path, sizeof(char) * (1 + ft_strlen(path_tmp) + 1));
		ft_bzero(path, (1 + ft_strlen(path_tmp) + 1));
		path[0] = '~';
		ft_strlcat(path, path_tmp, (1 + ft_strlen(path_tmp) + 1));
		free(path_tmp);
	}
	return (path);
}

void		ft_prompt(void)
{
	char	cwd_buffer[MAX_CMD_LINE];
	char	*cwd;
	char	*path;
	char	*username;

	ft_bzero(cwd_buffer, MAX_CMD_LINE);
	cwd = getcwd(cwd_buffer, MAX_CMD_LINE);
	path = construct_path(cwd);
	username = construct_username();
	ft_putstr_fd("\e[1;32m", 1);
	ft_putstr_fd(username, 1);
	ft_putstr_fd("@minishell\e[0m:\e[1;94m", 1);
	ft_putstr_fd(path, 1);
	ft_putstr_fd("\e[0m$ ", 1);
	free(path);
}

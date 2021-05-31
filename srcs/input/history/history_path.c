/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:46:41 by atrouill          #+#    #+#             */
/*   Updated: 2021/05/31 20:43:26 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

/*
**	Check if path is correct, with ending slash
**
**	@param path Path to check (will be freed)
**
**	@return Clean path
*/
static char	*clean_path(char *path)
{
	int				len;
	char			*tmp;

	len = ft_strlen(path);
	if (path[len -1] != '/')
	{
		tmp = ft_strjoin(path, "/");
		return (tmp);
	}
	return (path);
}

/*
**	Allows you to define the path of the history backup file.
**	If HOME is defined in the environment, otherwise in the current directory
**
**	@return path defined
*/
char	*history_path()
{
	char	cwd_buffer[4096];
	char	*path;
	char	*base;
	char	*tmp;

	base = search_env("HOME");
	if (base == NULL)
	{
		ft_bzero(cwd_buffer, MAX_CMD_LINE);
		base = getcwd(cwd_buffer, MAX_CMD_LINE);
	}
	tmp = clean_path(base);
	path = ft_strjoin(tmp, HISTORY_PATH);
	free(tmp);
	g_glob->path = path;
	return (path);
}

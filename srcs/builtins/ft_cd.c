/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:21:42 by atrouill          #+#    #+#             */
/*   Updated: 2021/06/21 09:10:21 by atrouill         ###   ########.fr       */
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
		free(path);
		return (tmp);
	}
	return (path);
}

/*
**	See if the input path is absolute or relative.
**	If absolute, returned as is. If relative, replaced by the absolute path.
**
**	@param path Path to be checked
**
**	@return Absolute path
*/
static char	*convert_in_absolute(char *path)
{
	char	*absolute;
	char	*cwd;
	char	*cleaned_path;
	char	buf[4096];

	if (path[0] == '/')
		absolute = ft_strdup(path);
	else
	{
		cwd = ft_strdup(getcwd(buf, 4096));
		cleaned_path = clean_path(cwd);
		absolute = ft_strjoin(cleaned_path, path);
		free(cleaned_path);
	}
	return (absolute);
}

static char	*construct_path(t_list *cmd)
{
	char	*path;
	char	*home;

	if (cmd->next == NULL)
	{
		home = search_env("HOME");
		if (home == NULL)
		{
			ft_putstr_fd("minishell: cd: HOME not set\n", 2);
			return (NULL);
		}
		path = ft_strdup(home);
	}
	else
	{
		path = convert_in_absolute(cmd->next->content);
	}
	return (path);

}

int	ft_cd(t_list *cmd)
{
	char	*path;
	char	*pwd;
	char	buf[4096];
	char	*cwd;

	path = construct_path(cmd);
	if (path == NULL)
		return (1);
	pwd = search_env("PWD");
	printf("path : %s\n", path);
	if (chdir(path) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putendl_fd(strerror(errno), 2);
	}
	else
	{
		cwd = getcwd(buf, 4096);
		ft_modify_value("OLDPWD", pwd);
		ft_modify_value("PWD", cwd);
	}
	free(path);
	return (0);
}

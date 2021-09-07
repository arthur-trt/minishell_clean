/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:36:40 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/06 13:51:35 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	change_dir(char *path, char *user_entry)
{
	char	*pwd;
//	char	buf[4096];

	pwd = search_env("PWD");
	if (path == NULL || chdir(path) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(user_entry, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
		free(path);
		return (1);
	}
	else
	{
		if (pwd != NULL)
			ft_modify_value("OLDPWD", pwd);
		ft_modify_value("PWD", path);
	}
	free(path);
	return (0);
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
	else if (getcwd(buf, 4096) != NULL)
	{
		cwd = ft_strdup(getcwd(buf, 4096));
		cleaned_path = clean_path(cwd);
		absolute = ft_strjoin(cleaned_path, path);
		free(cleaned_path);
	}
	else
	{
		absolute = ft_strjoin(search_env("PWD"), path);
		ft_putstr_fd("cd: error retrieving current directory: getcwd: ", 2);
		ft_putendl_fd(strerror(errno), 2);
	}
	return (absolute);
}

static char	*construct_path(t_list *cmd)
{
	char	*path;

	path = NULL;
	if ((cmd->next->content[0] != '.'
			&& cmd->next->content[0] != '/')
		&& search_env("CDPATH") != NULL)
		path = search_cdpath(cmd->next->content);
	else
		path = convert_in_absolute(cmd->next->content);
	return (path);
}

static int	cd_env(char *env, char *user_entry)
{
	char	*path;

	if (search_env(env) == NULL)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(env, 2);
		ft_putstr_fd(" not set\n", 2);
		return (1);
	}
	if (ft_strcmp(search_env(env), "") != 0)
		path = ft_strdup(search_env(env));
	else
		path = ft_strdup(search_env("PWD"));
	user_entry = path;
	return (change_dir(path, user_entry));
}

int	ft_cd(t_list *cmd)
{
	char	*path;
	char	*user_entry;

	user_entry = NULL;
	if (cmd->next)
		user_entry = cmd->next->content;
	if (cmd->next && cmd->next->next != NULL)
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		return (1);
	}
	else if (cmd->next == NULL
		|| ft_strcmp(user_entry, "--") == 0
		|| ft_strcmp(user_entry, "~") == 0)
		return (cd_env("HOME", user_entry));
	else if (ft_strcmp(user_entry, "-") == 0)
		return (cd_env("OLDPWD", user_entry));
	path = construct_path(cmd);
	return (change_dir(path, user_entry));
}

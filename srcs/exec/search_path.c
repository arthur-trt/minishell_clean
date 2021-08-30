/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 15:53:57 by atrouill          #+#    #+#             */
/*   Updated: 2021/08/30 22:21:31 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	scan_dir(char *folder, char *exec_name, char **path)
{
	DIR				*dir;
	struct dirent	*entry;
	int				ret_code;

	ret_code = 127;
	dir = opendir(folder);
	if (dir != NULL)
	{
		entry = readdir(dir);
		while (entry != NULL && ret_code == 127)
		{
			if (ft_strcmp(exec_name, entry->d_name) == 0)
			{
				(*path) = ft_strjoin(folder, exec_name);
				if (can_exec(*path) == true)
					ret_code = 0;
				else
					ret_code = 126;
			}
			entry = readdir(dir);
		}
		free(dir);
	}
	return (ret_code);
}

static int	search_in_env(char *exec_name, char **final_path)
{
	char	**tmp;
	char	*env;
	int		ret_code;
	int		i;

	env = search_env("PATH");
	ret_code = 127;
	if (env != NULL)
	{
		*final_path = NULL;
		tmp = ft_split(env, ':');
		i = 0;
		while (tmp[i] != NULL && ret_code == 127)
		{
			tmp[i] = clean_path(tmp[i]);
			ret_code = scan_dir(tmp[i], exec_name, final_path);
			i++;
		}
		free_split(tmp);
	}
	return (ret_code);
}

static int	search_in_path(char *exec_name, char **final_path)
{
	struct stat	f_stat;
	int			ret_code;
	char		buf[4096];
	char		*cwd;
	char		*tmp;

	ret_code = 127;
	if (exec_name[0] != '/')
	{
		cwd = ft_strdup(getcwd(buf, 4096));
		tmp = clean_path(cwd);
		*final_path = ft_strjoin(tmp, exec_name);
		free(tmp);
	}
	else
	{
		*final_path = exec_name;
	}
	if (stat(*final_path, &f_stat) == 0 && can_exec(*final_path) == false)
		ret_code = 126;
	if (can_exec(*final_path))
		ret_code = 0;
	return (ret_code);
}

/*
**	Test if user input is a path or a command name
**
**	@param exec_name user input
**
**	@return true if it's a command name, false otherwise
*/
static bool	is_command_name(char *exec_name)
{
	int	i;

	i = 0;
	while (exec_name[i] != '\0')
	{
		if (exec_name[i] == '/' || exec_name[i] == '.')
			return (false);
		i++;
	}
	return (true);
}

int	search_path(char *exec_name, char **path)
{
	int	ret_code;

	if (is_command_name(exec_name))
	{
		ret_code = search_in_env(exec_name, path);
	}
	else
	{
		ret_code = search_in_path(exec_name, path);
	}
	if (ret_code != 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(exec_name, 2);
		if (ret_code == 126)
			ft_putendl_fd(": Permission denied", 2);
		else if (ret_code == 127 && is_command_name(exec_name))
			ft_putendl_fd(": command not found", 2);
		else
			ft_putendl_fd(": No such file or directory", 2);
	}
	return (ret_code);
}

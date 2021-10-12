/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 15:53:57 by atrouill          #+#    #+#             */
/*   Updated: 2021/10/12 14:48:54 by jcueille         ###   ########.fr       */
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
			if (ft_strcmp(exec_name, entry->d_name) == 0
				&& entry->d_type != DT_DIR)
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
	if (is_dir(*final_path) == true)
		ret_code = 150;
	else if (stat(*final_path, &f_stat) == 0 && can_exec(*final_path) == false)
		ret_code = 126;
	else if (can_exec(*final_path))
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
	if (exec_name != NULL)
		if (ft_strncmp(exec_name, "./", 2) == 0
			|| ft_strncmp(exec_name, "../", 3) == 0
			|| ft_strncmp(exec_name, "/", 1) == 0)
			return (false);
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
		if (ret_code == 126)
			ft_putstrerror(exec_name, "Permission denied");
		else if (ret_code == 127 && is_command_name(exec_name) && search_env("PATH"))
			ft_putstrerror(exec_name, "command not found");
		else if (ret_code == 127 && !(is_command_name(exec_name)) && !(search_env("PATH")))
			ft_putstrerror(exec_name, "no such file or directory");
		else if (ret_code == 150)
		{
			ft_putstrerror(exec_name, ": is a directory");
			ret_code = 126;
		}
		else
			ft_putstrerror(exec_name, "No such file or directory");
	}
	return (ret_code);
}

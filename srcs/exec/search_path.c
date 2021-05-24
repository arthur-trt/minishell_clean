/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:16:07 by atrouill          #+#    #+#             */
/*   Updated: 2021/05/24 13:30:02 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Check if the user have permission to execute the file
**
**	@param path Path to file to check
**
**	@return True if user can exec, or false if not
*/
static bool	can_exec(char *path)
{
	struct stat		f_stat;

	if (stat(path, &f_stat) == 0)
	{
		if (f_stat.st_mode & S_IXUSR)
			return (true);
	}
	return (false);
}

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
**	Open dir and read all files for find a file with the same name
**
**	@param path Path to folder to scan
**	@param exec_name Name of the file to find
**
**	@return A clean path to the executable
*/
static char	*scan_dir(char *path, char *exec_name)
{
	DIR				*folder;
	struct dirent	*entry;
	char			*final_path;

	folder = opendir(path);
	entry = readdir(folder);
	while (entry != NULL)
	{
		if (ft_strcmp(exec_name, entry->d_name) == 0)
		{
			final_path = ft_strjoin(path, exec_name);
			if (can_exec(final_path) == true)
			{
				free(folder);
				return (final_path);
			}
		}
		entry = readdir(folder);
	}
	free(folder);
	return (NULL);
}

/*
**	Search exec in all PATH folder and in current dir
**
**	@param exec_name Exec to search in path
**
**	@return Return path + exec_name
*/
char	*search_path(char *exec_name)
{
	char			*path;
	int				i;
	char			**tmp;
	char			*test;

	path = search_env("PATH");
	tmp = ft_split(path, ':');
	i = 0;
	while (tmp[i] != NULL)
	{
		tmp[i] = clean_path(tmp[i]);
		test = scan_dir(tmp[i], exec_name);
		if (test != NULL)
		{
			free_split(tmp);
			return (test);
		}
		i++;
	}
	free_split(tmp);
	test = scan_dir("./", exec_name);
	if (test != NULL)
		return (test);
	return (NULL);
}

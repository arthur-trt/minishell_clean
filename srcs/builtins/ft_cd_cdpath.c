/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_cdpath.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 14:43:27 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/01 15:09:32 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Open dir and read all files for find a file with the same name
**
**	@param path Path to folder to scan
**	@param exec_name Name of the file to find
**
**	@return A clean path to the executable
*/
static char	*scan_dir(char *path, char *dir)
{
	DIR				*folder;
	struct dirent	*entry;
	char			*final_path;

	folder = opendir(path);
	if (folder != NULL)
	{
		entry = readdir(folder);
		while (entry != NULL)
		{
			final_path = ft_strjoin(path, dir);
			if (is_dir(final_path) == true)
			{
				free(folder);
				return (final_path);
			}
			free(final_path);
			entry = readdir(folder);
		}
		free(folder);
	}
	return (NULL);
}

/*
**	Search exec in all PATH folder and in current dir
**
**	@param exec_name Exec to search in path
**
**	@return Return path + exec_name
*/
char	*search_cdpath(char *dir)
{
	char			*path;
	int				i;
	char			**tmp;
	char			*test;

	path = search_env("CDPATH");
	if (path != NULL)
	{
		tmp = ft_split(path, ':');
		i = 0;
		while (tmp[i] != NULL)
		{
			tmp[i] = clean_path(tmp[i]);
			test = scan_dir(tmp[i], dir);
			if (test != NULL)
			{
				free_split(tmp);
				return (test);
			}
			i++;
		}
		free_split(tmp);
	}
	return (NULL);
}

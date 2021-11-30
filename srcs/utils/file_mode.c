/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:25:31 by atrouill          #+#    #+#             */
/*   Updated: 2021/11/30 09:44:51 by atrouill         ###   ########.fr       */
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
bool	can_exec(char *path)
{
	struct stat		f_stat;

	if (stat(path, &f_stat) == 0)
	{
		if ((f_stat.st_mode & S_IXUSR))
			return (true);
	}
	return (false);
}

/*
** Check if the path given is a dir or not
**
** @param path Path to file to check
**
** @return True if it's a dir, false otherwise
*/
bool	is_dir(char *path)
{
	struct stat		f_stat;

	if (stat(path, &f_stat) == 0)
	{
		if (S_ISDIR(f_stat.st_mode))
			return (true);
	}
	return (false);
}

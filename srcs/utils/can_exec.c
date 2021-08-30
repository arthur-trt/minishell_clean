/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:25:31 by atrouill          #+#    #+#             */
/*   Updated: 2021/08/30 16:25:40 by atrouill         ###   ########.fr       */
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
		if (f_stat.st_mode & S_IXUSR)
			return (true);
	}
	return (false);
}

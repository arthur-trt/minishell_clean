/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:35:50 by atrouill          #+#    #+#             */
/*   Updated: 2021/08/13 15:36:07 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Check if path is correct, with ending slash
**
**	@param path Path to check (will be freed)
**
**	@return Clean path
*/
char	*clean_path(char *path)
{
	int				len;
	char			*tmp;

	len = ft_strlen(path);
	if (path[len - 1] != '/')
	{
		tmp = ft_strjoin(path, "/");
		free(path);
		return (tmp);
	}
	return (path);
}


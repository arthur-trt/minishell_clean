/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 16:31:29 by atrouill          #+#    #+#             */
/*   Updated: 2021/05/29 18:17:55 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

static t_hist	*last_elem(t_hist *hist)
{
	while (hist->next)
	{
		hist = hist->next;
	}
	return (hist);
}

/*
**	Save the history in a file
**
**	@param hist Linked list representing the history
**
**	@return False if the operation failed, true otherwise
*/
bool	backup_history(t_hist *hist)
{
	int		fd;
	t_hist	*last;

	if (hist == NULL)
		return (false);
	fd = open(g_glob->path, O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		return (false);
	last = last_elem(hist);
	while (last)
	{
		ft_putendl_fd(last->line, fd);
		last = last->prev;
	}
	close (fd);
	return (true);
}

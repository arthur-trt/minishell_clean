/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_hist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 10:32:04 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/26 16:00:07 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Retrieves the old history from the file and saves it in the linked list
**
**	@return Linked list representing the history
*/
t_hist	*construct_hist(void)
{
	int			fd;
	char		*line;
	t_hist		*hist;

	hist = NULL;
	fd = open(HISTORY_PATH, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (get_next_line(fd, &line))
	{
		append_history(line, &hist);
		free(line);
	}
	free(line);
	close(fd);
	return (hist);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:58:54 by atrouill          #+#    #+#             */
/*   Updated: 2021/10/21 11:48:16 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	history_append(char *cmd)
{
	int	fd;

	fd = open(HISTORY_PATH, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd != -1)
	{
		ft_putendl_fd(cmd, fd);
		close(fd);
	}
	add_history(cmd);
}

void	load_history(void)
{
	int		fd;
	char	*cmd;

	using_history();
	fd = open(HISTORY_PATH, O_RDONLY);
	if (fd != -1)
	{
		while (get_next_line(fd, &cmd) != 0)
		{
			add_history(cmd);
			free(cmd);
		}
		free(cmd);
		close(fd);
	}
}

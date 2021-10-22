/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:58:54 by atrouill          #+#    #+#             */
/*   Updated: 2021/10/22 16:14:33 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*obtain_path(void)
{
	static char	*tmp = NULL;
	static char	*path = NULL;
	char		buff[4096];

	if (tmp == NULL && path == NULL)
	{
		tmp = getcwd(buff, 4096);
		path = ft_strjoin(tmp, "/" HISTORY_PATH);
		printf("path %s\n", path);
	}
	return (path);
}

void	history_append(char *cmd)
{
	int		fd;
	char	*path;

	path = obtain_path();
	fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
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
	char	*path;

	path = obtain_path();
	using_history();
	fd = open(path, O_RDONLY);
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

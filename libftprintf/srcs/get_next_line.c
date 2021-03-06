/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 20:09:13 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/07 21:38:36 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int	free_ret(char **cache, int ret)
{
	if (*cache)
	{
		free(*cache);
		*cache = NULL;
	}
	return (ret);
}

static ssize_t	locate_n(char *str, char c)
{
	ssize_t	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == c)
			return (index);
		index++;
	}
	return (-1);
}

static int	obtain_line(char **cache, char **line)
{
	ssize_t	index;
	char	*tmp;

	index = locate_n(*cache, '\n');
	if (index < 0)
	{
		*line = ft_strdup(*cache);
		return (free_ret(cache, 0));
	}
	*line = ft_substr(*cache, 0, index);
	tmp = ft_substr(*cache, index + 1, ft_strlen(*cache) - index - 1);
	free(*cache);
	*cache = tmp;
	return (1);
}

static int	get_next_line_helper(ssize_t read_size, char **cache, char **line)
{
	if (read_size < 0)
		return (free_ret(cache, -1));
	if (read_size == 0 && (ft_strncmp(*cache, "", ft_strlen(*cache)) == 0))
	{
		*line = ft_strdup("");
		return (free_ret(cache, 0));
	}
	return (obtain_line(cache, line));
}

int	get_next_line(int fd, char **line)
{
	static char	*cache;
	ssize_t		read_size;
	char		*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || !line || BUFFER_SIZE < 1 || !(buffer))
		return (free_ret(&cache, -1));
	read_size = read(fd, buffer, BUFFER_SIZE);
	while (read_size > 0)
	{
		buffer[read_size] = '\0';
		if (!(ft_strjoin_gnl(&cache, buffer)))
			return (free_ret(&cache, -1));
		if (locate_n(cache, '\n') != -1)
			break ;
		read_size = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (get_next_line_helper(read_size, &cache, line));
}

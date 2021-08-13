/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:52:04 by atrouill          #+#    #+#             */
/*   Updated: 2020/06/11 16:03:55 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_buffer	*init_buffer(t_buffer *buffer)
{
	if (!(buffer = malloc(sizeof(t_buffer))))
		return (NULL);
	buffer->len = BUFFER_SIZE;
	buffer->data_len = 0;
	buffer->last_pos = 0;
	buffer->written = 0;
	if (!(buffer->buffer = malloc(sizeof(char) * buffer->len)))
		return (NULL);
	return (buffer);
}

t_buffer	*check_data_len(t_buffer **buffer)
{
	t_buffer	*new_buff;

	new_buff = NULL;
	if ((*buffer)->len > BUFFER_SIZE)
	{
		if (!(new_buff = init_buffer(new_buff)))
			return (0);
		new_buff->written = (*buffer)->written +
			write(1, (*buffer)->buffer, (*buffer)->data_len);
		free((*buffer));
		return (new_buff);
	}
	return (*buffer);
}

int			add_char_buffer(t_buffer **buff, char c)
{
	if ((*buff)->data_len >= (*buff)->len)
	{
		(*buff)->len += 50;
		if (!((*buff)->buffer = ft_realloc((*buff)->buffer,	(*buff)->len)))
			return (0);
	}
	(*buff)->buffer[(*buff)->data_len] = c;
	(*buff)->data_len += 1;
	return (1);
}

int			add_str_buffer(t_buffer **buff, char *str)
{
	while (*str)
	{
		if (!(add_char_buffer(buff, *str)))
			return (0);
		str++;
	}
	return (1);
}

int			add_char_last_pos_buffer(t_buffer **buff, char c)
{
	if ((*buff)->data_len >= (*buff)->len)
	{
		(*buff)->len += 50;
		if (!((*buff)->buffer = ft_realloc((*buff)->buffer, (*buff)->len)))
			return (0);
	}
	if (!(ft_memmove((*buff)->buffer + (*buff)->last_pos + 1,
		(*buff)->buffer + (*buff)->last_pos,
		(*buff)->data_len - (*buff)->last_pos)))
		return (0);
	(*buff)->buffer[(*buff)->last_pos] = c;
	(*buff)->data_len += 1;
	return (1);
}

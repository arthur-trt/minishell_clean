/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 19:55:52 by atrouill          #+#    #+#             */
/*   Updated: 2020/04/06 18:14:26 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	treat_min_width(t_buffer **buffer, t_parsing *parsed)
{
	int	len;
	int	i;

	len = (*buffer)->data_len - (*buffer)->last_pos;
	i = 0;
	while (len + i < parsed->min_width)
	{
		if (!add_char_last_pos_buffer(buffer, ' '))
			return (0);
		i++;
	}
	return (1);
}

int	treat_left_padded(t_buffer **buffer, t_parsing *parsed)
{
	int	len;
	int	i;

	len = (*buffer)->data_len - (*buffer)->last_pos;
	i = 0;
	while (len + i < parsed->min_width)
	{
		if (!add_char_buffer(buffer, ' '))
			return (0);
		i++;
	}
	return (1);
}

int	treat_zero_padded(t_buffer **buffer, t_parsing *parsed)
{
	int	len;
	int	i;

	if (((*buffer)->buffer[(*buffer)->last_pos] == '-') &&
		(parsed->conv & CONV_INT) != 0)
	{
		parsed->min_width -= 1;
		(*buffer)->last_pos += 1;
	}
	len = (*buffer)->data_len - (*buffer)->last_pos;
	i = 0;
	while (len + i < parsed->min_width)
	{
		if (!add_char_last_pos_buffer(buffer, '0'))
			return (0);
		i++;
	}
	return (1);
}

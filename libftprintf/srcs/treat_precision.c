/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 18:44:40 by atrouill          #+#    #+#             */
/*   Updated: 2020/04/06 18:14:26 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	treat_precision(t_buffer **buffer, t_parsing *parsed)
{
	if (conv_is_num(parsed->conv))
	{
		if ((parsed->conv & CONV_PTR) != 0)
		{
			(*buffer)->last_pos += 2;
			return (precision_number(buffer, parsed));
		}
		return (precision_number(buffer, parsed));
	}
	if ((parsed->conv & CONV_STR) != 0)
		return (precision_str(buffer, parsed));
	return (1);
}

int	precision_number(t_buffer **buffer, t_parsing *parsed)
{
	int	i;
	int	len;
	int	neg;

	if ((*buffer)->data_len - (*buffer)->last_pos == 1)
		if ((*buffer)->buffer[(*buffer)->last_pos] == '0' &&
			(parsed->precision) == 0)
		{
			(*buffer)->data_len -= 1;
			return (1);
		}
	neg = 0;
	if (((*buffer)->buffer[(*buffer)->last_pos] == '-') &&
		(parsed->conv & CONV_INT) != 0)
		neg = 1;
	i = 0;
	(*buffer)->last_pos += neg;
	len = (*buffer)->data_len - (*buffer)->last_pos;
	while (len + i++ < parsed->precision)
		if (!add_char_last_pos_buffer(buffer, '0'))
			return (0);
	(*buffer)->last_pos -= neg;
	return (1);
}

int	precision_str(t_buffer **buffer, t_parsing *parsed)
{
	int	len;

	len = (*buffer)->data_len - (*buffer)->last_pos;
	if (len > parsed->precision)
	{
		(*buffer)->data_len -= (len - parsed->precision);
	}
	return (1);
}

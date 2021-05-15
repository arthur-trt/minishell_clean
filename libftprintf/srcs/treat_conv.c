/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:53:03 by atrouill          #+#    #+#             */
/*   Updated: 2020/04/06 18:14:25 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	treat_conv(t_buffer **buffer, t_parsing *parsed, va_list *args)
{
	*buffer = check_data_len(buffer);
	(*buffer)->last_pos = (*buffer)->data_len;
	if (!(call_conv(buffer, parsed, args)))
		return (0);
	if (!(call_flags(buffer, parsed)))
		return (0);
	return (1);
}

int	call_conv(t_buffer **buffer, t_parsing *parsed, va_list *args)
{
	if ((parsed->conv & CONV_CHAR) != 0)
		return (conv_c(buffer, args));
	if ((parsed->conv & CONV_STR) != 0)
		return (conv_s(buffer, args));
	if ((parsed->conv & CONV_INT) != 0)
		return (conv_d(buffer, args));
	if ((parsed->conv & CONV_PTR) != 0)
		return (conv_p(buffer, args));
	if ((parsed->conv & PRINT_PERCENT) != 0)
		return (conv_percent(buffer));
	if ((parsed->conv & CONV_UNSIGNED) != 0)
		return (conv_u(buffer, args));
	if ((parsed->conv & CONV_HEX) != 0)
		return (conv_x(buffer, args, "0123456789abcdef"));
	if ((parsed->conv & CONV_HEX_MAJ) != 0)
		return (conv_x(buffer, args, "0123456789ABCDEF"));
	else
		return (0);
}

int	call_flags(t_buffer **buffer, t_parsing *parsed)
{
	if ((parsed->flags & FLAG_PRECISION) != 0)
		if ((!treat_precision(buffer, parsed)))
			return (0);
	if (((parsed->flags == FLAG_PRECISION) || (parsed->flags == 0))
		&& (parsed->min_width != 0))
		if ((!treat_min_width(buffer, parsed)))
			return (0);
	if ((parsed->flags & FLAG_L_PADDED) != 0)
		if ((!treat_left_padded(buffer, parsed)))
			return (0);
	if ((parsed->flags & FLAG_0_PADDED) != 0)
	{
		if (conv_is_num(parsed->conv) && (parsed->flags & FLAG_PRECISION) != 0)
		{
			if (!treat_min_width(buffer, parsed))
				return (0);
		}
		else if ((!treat_zero_padded(buffer, parsed)))
			return (0);
	}
	return (1);
}

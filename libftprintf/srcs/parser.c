/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 20:49:22 by atrouill          #+#    #+#             */
/*   Updated: 2020/04/06 18:14:25 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_parsing	*parse_format(const char **format, va_list *args)
{
	t_parsing	*parsed;

	parsed = NULL;
	if (!(parsed = init_parsing_struct(parsed)))
		return (NULL);
	(*format) += 1;
	parse_flags(format, args, parsed);
	parse_conv(**format, parsed);
	return (parsed);
}

void		parse_flags(const char **format, va_list *args, t_parsing *parsed)
{
	while (((**format) != '\0') && (!(is_converter(**format))))
	{
		if ((**format) == '*')
			parse_star(args, parsed);
		else if (((**format) == '0') && *(*format - 1) == '%')
			parsed->flags |= FLAG_0_PADDED;
		else if ((**format) == '-')
			parsed->flags |= FLAG_L_PADDED;
		else if ((**format) == '.')
			parsed->flags |= FLAG_PRECISION;
		else if ((**format) >= '0' && ((**format) <= '9'))
		{
			if ((parsed->flags & FLAG_PRECISION) != 0)
				parsed->precision = (parsed->precision * 10)
					+ ((**format) - '0');
			else
				parsed->min_width = (parsed->min_width * 10)
					+ ((**format) - '0');
		}
		(*format)++;
	}
}

void		parse_star(va_list *args, t_parsing *parsed)
{
	if ((parsed->flags & FLAG_PRECISION) != 0)
	{
		parsed->precision = va_arg(*args, int);
		if (parsed->precision < 0)
		{
			parsed->flags ^= FLAG_PRECISION;
			parsed->precision = 0;
		}
	}
	else
	{
		parsed->min_width = va_arg(*args, int);
		if (parsed->min_width < 0)
		{
			parsed->flags |= FLAG_L_PADDED;
			parsed->min_width *= -1;
		}
	}
}

void		parse_conv(char format, t_parsing *parsed)
{
	if (format == 'c')
		parsed->conv = CONV_CHAR;
	else if (format == 's')
		parsed->conv = CONV_STR;
	else if (format == 'p')
		parsed->conv = CONV_PTR;
	else if (format == 'd' || format == 'i')
		parsed->conv = CONV_INT;
	else if (format == 'u')
		parsed->conv = CONV_UNSIGNED;
	else if (format == 'x')
		parsed->conv = CONV_HEX;
	else if (format == 'X')
		parsed->conv = CONV_HEX_MAJ;
	else if (format == '%')
		parsed->conv = PRINT_PERCENT;
}

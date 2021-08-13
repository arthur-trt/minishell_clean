/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 09:48:38 by atrouill          #+#    #+#             */
/*   Updated: 2020/04/06 18:14:25 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_parsing	*parsed;
	t_buffer	*buffer;

	buffer = NULL;
	if ((format == NULL) || (!(buffer = init_buffer(buffer))))
		return (EXIT_FAILURE);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			parsed = parse_format(&format, &args);
			treat_conv(&buffer, parsed, &args);
			free(parsed);
		}
		else
			add_char_buffer(&buffer, *format);
		format++;
	}
	return (write(1, buffer->buffer, buffer->data_len) + buffer->written);
}

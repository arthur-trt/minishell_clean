/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:01:13 by atrouill          #+#    #+#             */
/*   Updated: 2020/04/06 18:14:24 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	conv_s(t_buffer **buffer, va_list *args)
{
	char	*str;

	if (!(str = va_arg(*args, char *)))
	{
		if (!(add_str_buffer(buffer, "(null)")))
			return (0);
		return (1);
	}
	if (!(add_str_buffer(buffer, str)))
		return (0);
	return (1);
}

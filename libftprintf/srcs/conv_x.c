/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:39:47 by atrouill          #+#    #+#             */
/*   Updated: 2020/04/06 18:14:24 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	conv_x(t_buffer **buffer, va_list *args, char *hex)
{
	unsigned int	nbr;
	char			*res;

	nbr = va_arg(*args, unsigned int);
	if (!(res = conv_to_hex(nbr, hex)))
		return (0);
	if (!(add_str_buffer(buffer, res)))
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:15:22 by atrouill          #+#    #+#             */
/*   Updated: 2020/04/06 18:14:23 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	conv_p(t_buffer **buffer, va_list *args)
{
	long	addr;
	char	*res;

	if (!(addr = va_arg(*args, long)))
	{
		addr = 0;
	}
	if (!(res = conv_to_hex(addr, "0123456789abcdef")))
		return (0);
	if (!(add_str_buffer(buffer, "0x")))
		return (0);
	if (!(add_str_buffer(buffer, res)))
		return (0);
	return (1);
}

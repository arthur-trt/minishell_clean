/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:33:35 by atrouill          #+#    #+#             */
/*   Updated: 2020/04/06 18:14:24 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	conv_u(t_buffer **buffer, va_list *args)
{
	unsigned int	res;
	char			*str;

	res = va_arg(*args, unsigned int);
	if (!(str = ft_itoa(res)))
		return (0);
	if (!(add_str_buffer(buffer, str)))
		return (0);
	return (1);
}

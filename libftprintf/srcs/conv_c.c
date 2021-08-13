/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:49:00 by atrouill          #+#    #+#             */
/*   Updated: 2020/04/06 18:14:23 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	conv_c(t_buffer **buffer, va_list *args)
{
	int	c;

	c = va_arg(*args, int);
	if (!(add_char_buffer(buffer, c)))
		return (0);
	return (1);
}

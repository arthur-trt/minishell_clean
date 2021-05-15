/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:10:21 by atrouill          #+#    #+#             */
/*   Updated: 2020/04/06 18:14:23 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	conv_d(t_buffer **buffer, va_list *args)
{
	int		res;
	char	*str;

	res = va_arg(*args, int);
	if (!(str = ft_itoa(res)))
		return (0);
	if (!(add_str_buffer(buffer, str)))
		return (0);
	return (1);
}

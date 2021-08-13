/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:31:09 by atrouill          #+#    #+#             */
/*   Updated: 2020/04/06 18:14:23 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	conv_percent(t_buffer **buffer)
{
	if (!(add_char_buffer(buffer, '%')))
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 09:24:19 by atrouill          #+#    #+#             */
/*   Updated: 2021/08/13 20:25:08 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
**	Converts the letter c to lower case if possible.
**
**	@param c Char to lower
**
**	@return The value returned is the converted letter,
**	or c if the conversion was not possible.
*/
int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

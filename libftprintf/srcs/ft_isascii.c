/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:21:34 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/21 12:03:30 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
**	Test if a number code is a valid ASCII code
**
**	@param c number to test
**
**	@return true if ASCII code / false if not
*/
bool	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (true);
	return (false);
}

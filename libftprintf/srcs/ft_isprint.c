/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 09:06:39 by atrouill          #+#    #+#             */
/*   Updated: 2021/03/08 11:20:29 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
**	Test if an ASCII code is a printable character
**
**	@param c ASCII code to test (can be a char)
**
**	@return true if printable / false if not
*/
bool	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (true);
	return (false);
}

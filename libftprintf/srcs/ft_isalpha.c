/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:24:04 by atrouill          #+#    #+#             */
/*   Updated: 2021/03/08 11:18:41 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
**	Test if an ASCII code is an alphabetical character
**
**	@param c ASCII code to test (can be a char)
**
**	@return true if alphabetical / false if not
*/
bool	ft_isalpha(int c)
{
	if ((!((c >= 'A' && c <= 'Z')
			|| (c >= 'a' && c <= 'z'))))
		return (false);
	return (true);
}

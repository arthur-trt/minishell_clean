/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:00:22 by atrouill          #+#    #+#             */
/*   Updated: 2021/03/08 11:20:00 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
**	Test if an ASCII code is an numercial character
**
**	@param c ASCII code to test (can be a char)
**
**	@return true if numerical / false if not
*/
bool	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

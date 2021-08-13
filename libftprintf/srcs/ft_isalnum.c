/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:13:35 by atrouill          #+#    #+#             */
/*   Updated: 2021/03/08 11:17:34 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
**	Test if an ASCII code is an alphanumeric character
**
**	@param c ASCII code to test (can be a char)
**
**	@return true if alphanumeric / false if not
*/
bool	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (true);
	return (false);
}

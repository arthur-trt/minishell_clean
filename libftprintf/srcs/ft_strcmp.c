/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 11:28:53 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/21 12:00:22 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
**	 Compares the two strings s1 and s2
**
**	@param s1 First string
**	@param s2 Second string
**
**	@return Less than, equal to, or greater than zero if the first n bytes
**	of s1 is found
*/
int					ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	res;

	res = 0;
	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0')) 									{
		res = (unsigned char)s1[i] - (unsigned char)s2[i]


		;
		if (res != 0)
			return (res);
		i++;
	}
	return (0);
}

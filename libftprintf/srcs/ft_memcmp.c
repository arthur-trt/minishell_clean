/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 09:17:04 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/21 11:38:35 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
**	Compares the first n bytes (each interpreted as unsigned char)
**	of the memory areas s1 and s2
**
**	@param s1 First memory aera
**	@param s2 Second memory aera
**	@param n Number of bytes to scan
**
**	@return Less than, equal to, or greater than zero if the first n bytes
**	of s1 is found
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1c;
	unsigned char	*s2c;
	size_t			i;

	i = 0;
	s1c = (unsigned char *)s1;
	s2c = (unsigned char *)s2;
	while (s1c[i] == s2c[i] && i < n - 1)
		i++;
	if (i == n)
		return (0);
	return (s1c[i] - s2c[i]);
}

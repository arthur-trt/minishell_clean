/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 09:48:19 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/21 11:36:32 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
** Scans  the  initial  n  bytes of the memory area pointed to by s for the
**	first instance of c.
**	Both c and the bytes of the memory area pointed to by s are interpreted as
**	unsigned char.
**
**	@param s Memory zone where to search
**	@param c Bytes to search
**	@param n Size of the field of search
**
**	@return Pointer to the matching byte or NULL
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *s0;

	s0 = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*s0 == (unsigned char)c)
			return ((void *)s0);
		s0++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:56:58 by atrouill          #+#    #+#             */
/*   Updated: 2021/03/08 13:16:55 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
**	Copy bytes from src to dst, until c occurs in src or until n element have been copied
**
**	@param dst Pointer to destination string
**	@param src Pointer to source string
**	@param c Char who stop the copy if occurs
**	@param n Maximal size of copy
**
**	@return Pointer to dst if c have been reaching
*/
void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst0;
	unsigned char	*src0;
	size_t			i;

	i = 0;
	dst0 = (unsigned char *)dst;
	src0 = (unsigned char *)src;
	while (i < n)
	{
		dst0[i] = src0[i];
		if (src0[i] == (unsigned char)c)
			return ((void *)(dst0 + i + 1));
		i++;
	}
	return (NULL);
}

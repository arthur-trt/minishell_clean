/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:22:56 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/21 11:40:25 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
**	Copies n bytes from memory area src to memory area dest.
**
**	@param dst Destination of the copy
**	@param src Source of the copy
**	@param n Size of the copy
**
**	@return Pointer to dest
*/
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *dst0;
	unsigned char *src0;

	dst0 = (unsigned char *)dst;
	src0 = (unsigned char *)src;
	if (n == 0 || dst0 == src0)
		return (dst);
	while (n--)
		*dst0++ = *src0++;
	return (dst);
}

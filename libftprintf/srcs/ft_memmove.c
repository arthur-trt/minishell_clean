/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:20:56 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/21 11:46:40 by atrouill         ###   ########.fr       */
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
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*src0;
	unsigned char	*dst0;

	src0 = (unsigned char *)src;
	dst0 = (unsigned char *)dst;
	if (!src0 && !dst0)
		return (NULL);
	if (dst0 >= src0)
		while (len-- > 0)
			dst0[len] = src0[len];
	else
		ft_memcpy(dst0, src0, len);
	return (dst);
}

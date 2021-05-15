/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:22:56 by atrouill          #+#    #+#             */
/*   Updated: 2020/04/06 18:12:42 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

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

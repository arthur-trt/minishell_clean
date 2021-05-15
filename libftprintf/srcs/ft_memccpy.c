/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:56:58 by atrouill          #+#    #+#             */
/*   Updated: 2020/04/06 18:12:41 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

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

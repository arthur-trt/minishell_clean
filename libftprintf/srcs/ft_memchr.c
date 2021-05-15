/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 09:48:19 by atrouill          #+#    #+#             */
/*   Updated: 2020/04/06 18:12:41 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

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

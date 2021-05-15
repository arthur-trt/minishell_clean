/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:16:21 by atrouill          #+#    #+#             */
/*   Updated: 2020/04/06 18:12:44 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	strlend;
	size_t	strlens;

	strlend = ft_strlen(dst);
	strlens = ft_strlen(src);
	i = 0;
	if (dstsize <= strlend)
		return (strlens + dstsize);
	while (i < dstsize - strlend - 1 && src[i])
	{
		dst[strlend + i] = src[i];
		i++;
	}
	dst[strlend + i] = 0;
	return (strlens + strlend);
}

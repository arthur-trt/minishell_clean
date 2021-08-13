/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:16:21 by atrouill          #+#    #+#             */
/*   Updated: 2021/08/13 20:26:04 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
**	Concatenate strings. Take the full size of the buffer (not just the length)
**	and guarantee to NUL-terminate the result as long as long as there is at
**	least one byte free in dst. Note that a byte for the NUL should be
**	includedin size.
**
**	@param dst Destination string
**	@param src Source string
**	@param dstsize Destination size
**
**	@return The initial length of dst plus the length of src
*/
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:09:42 by atrouill          #+#    #+#             */
/*   Updated: 2021/08/13 20:06:32 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
**	Copy strings. Take the full size of the buffer (not just the length)
**	and guarantee to NUL-terminate the result as long as size is larger than 0.
**	Note that a byte for the NUL should be included in size.
**
**	@param dst Destination string
**	@param src Source string
**	@param dstsize Destination size
**
**	@return The initial length of dst plus the length of src
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	i;

	if (!dst || !src)
		return (0);
	srclen = ft_strlen(src);
	i = 0;
	if (!dstsize)
		return (srclen);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:26:51 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/21 11:48:31 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
**	Fills the first n bytes of the memory area pointed to by b with the
**	constant byte c.
**
**	@param b Area to fill
**	@param c Byte used for fill
**	@param len Number of byte to write
**
**	@return Pointer to the memory area s
*/
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *ptr;

	ptr = b;
	while (len-- > 0)
		*ptr++ = c;
	return (b);
}

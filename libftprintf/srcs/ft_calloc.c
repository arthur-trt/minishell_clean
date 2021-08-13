/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:59:29 by atrouill          #+#    #+#             */
/*   Updated: 2021/03/08 11:17:59 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
**	Allocates space for count objects that are size bytes.
**	The allocated memory is filled with bytes of value zero.
**
**	@param count Number of objects to allocate space
**	@param size Size of each objects
**
**	@return A pointer to allocated memory
*/
void	*ft_calloc(size_t count, size_t size)
{
	void *ret;

	if (!(ret = malloc(count * size)))
		return (NULL);
	return (ft_memset(ret, 0, count * size));
}

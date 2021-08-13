/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:59:29 by atrouill          #+#    #+#             */
/*   Updated: 2021/08/13 19:32:37 by atrouill         ###   ########.fr       */
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
	void	*ret;

	ret = malloc(count * size);
	if (!(ret))
		return (NULL);
	return (ft_memset(ret, 0, count * size));
}

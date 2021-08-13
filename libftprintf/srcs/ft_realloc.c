/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:45:55 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/21 11:53:55 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
**	Changes the size of the memory block pointed to by ptr to size bytes.
**
**	@param ptr Memory block
**	@param size New size
**
**	@return Pointer to the newly allocated memory
*/
void	*ft_realloc(void *ptr, size_t size)
{
	char	*newptr;

	if (!size && ptr)
	{
		if (!(newptr = (char *)malloc(1)))
			return (NULL);
		ft_memdel(&ptr);
		return (newptr);
	}
	if (!(newptr = (char *)malloc(size)))
		return (NULL);
	if (ptr)
	{
		ft_memcpy(newptr, ptr, size);
		ft_memdel(&ptr);
	}
	return (newptr);
}

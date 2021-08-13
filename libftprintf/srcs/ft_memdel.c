/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 16:01:41 by atrouill          #+#    #+#             */
/*   Updated: 2021/08/13 19:48:27 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
**	Takes as a parameter the address of a pointer whose pointed area must
**	be freed with free(3), then the pointer is set to NULL
**
**	@param ap The address of a pointer whose memory must be freed and
**	then set it to NULL.
**
*/
void	ft_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

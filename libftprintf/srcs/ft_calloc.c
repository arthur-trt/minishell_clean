/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:59:29 by atrouill          #+#    #+#             */
/*   Updated: 2020/04/06 18:12:57 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *ret;

	if (!(ret = malloc(count * size)))
		return (NULL);
	return (ft_memset(ret, 0, count * size));
}

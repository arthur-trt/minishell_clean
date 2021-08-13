/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:59:37 by atrouill          #+#    #+#             */
/*   Updated: 2021/03/08 11:10:26 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
**	Write n zeroed bytes to the string s
**
**	@param s String where the zeros will be writed
**	@param n Number of zero to write
*/
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

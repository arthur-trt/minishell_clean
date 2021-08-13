/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:19:06 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/21 11:50:01 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
**	Write a character in the desired fd
**
**	@param c Character to be written
**	@param fd FD in which to write
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

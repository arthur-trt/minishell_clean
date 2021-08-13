/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:29:50 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/21 11:52:00 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
**	Write a number in the desired fd
**
**	@param n Number to be written
**	@param fd FD in which to write
*/
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		n = -1 * n;
		ft_putchar_fd('-', fd);
	}
	if (n / 10 > 0)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

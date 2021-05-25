/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_win_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:04:55 by atrouill          #+#    #+#             */
/*   Updated: 2021/05/25 16:32:49 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <termios.h>
#include <sys/ioctl.h>

/*
**	Allows you to obtain the size of the terminal window in number of characters
**	per row and per column.
**	Uses ioctl and not termcaps because it doesn't take into account size
**	changes if done after program launch
**
**	@return Structure containing the size in column and row
*/
t_size	get_win_size(void)
{
	t_size			win;
	struct winsize	w;

	win.col = 0;
	win.row = 0;
	if (ioctl(0, TIOCGWINSZ, &w))
		return (win);
	win.col = w.ws_col;
	win.row = w.ws_row;
	return (win);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 15:01:12 by atrouill          #+#    #+#             */
/*   Updated: 2021/05/29 18:18:23 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Allows you to obtain the current position of the cursor in the terminal.
**	Writes the escape sequence: "\e[6n", then reads a response in the terminal
**	of the form: "[<ROW>;<COL>R"
**
**	I don't know why, but the rows start with at 1 and the columns at 0
**
**	@return Structure containing the position in rows and columns
*/
t_size	get_current_cursor_position(void)
{
	t_size	pos;
	char	answer[20];
	int		i;

	ft_bzero(answer, 20);
	ft_putstr_fd("\e[6n", 0);
	read(0, answer, 20);
	i = 2;
	pos.row = ft_atoi(answer + i);
	while (ft_isdigit(answer[i]))
		i++;
	pos.col = ft_atoi(answer + i + 1);
	return (pos);
}

/*
**	Allows you to place the cursor in the terminal according to the starting
**	position and the relative position of the cursor
**
**	@param input Structure containing information about the typed line
*/
void	set_cursor_pos(t_line input)
{
	t_size	pos;

	pos.col = input.cursor_pos.col + input.cursor % input.win_size.col;
	pos.row = input.cursor_pos.row + input.cursor / input.win_size.col;
	if (pos.col > input.win_size.col)
	{
		pos.col %= input.win_size.col;
		if (pos.row + 1 <= input.win_size.row)
			pos.row++;
	}
	tputs(tgoto(tgetstr("cm", NULL), pos.col - 1, pos.row - 1), 0, &outfun);
}

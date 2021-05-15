/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor_lines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:10:28 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/24 17:42:00 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Moves the cursor to the previous line in the same col
**
**	@param input Structure t_line
*/
void	move_cursor_prev_line(t_line *input)
{
	if (input->cursor_pos.col + input->cursor < input->win_size.col)
		return ;
	input->cursor -= input->win_size.col;
	if (input->cursor < 0 || input->cursor > input->lenght)
		input->cursor = 0;
	set_cursor_pos(*input);
}

void	move_cursor_next_line(t_line *input)
{
	t_size	curr;
	t_size	max;

	curr.col = input->cursor_pos.col + input->cursor % input->win_size.col;
	curr.row = input->cursor_pos.row + input->cursor / input->win_size.col;
	if (curr.col > input->win_size.col)
	{
		curr.col = curr.col % input->win_size.col;
		curr.row++;
	}
	max.col = input->cursor_pos.col + input->lenght % input->win_size.col;
	max.row = input->cursor_pos.row + input->lenght / input->win_size.col;
	if (max.col > input->win_size.col)
	{
		max.col = max.col % input->win_size.col;
		max.row++;
	}
	if (curr.row >= max.row)
		return ;
	input->cursor += input->win_size.col;
	if (input->cursor > input->lenght)
		input->cursor = input->lenght;
	set_cursor_pos(*input);
}

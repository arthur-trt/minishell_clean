/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:47:31 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/23 19:43:55 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Move the cursor to the left
**
**	@param input Structure t_line
*/
void	move_cursor_left(t_line *input)
{
	if (input->cursor == 0)
		return ;
	input->cursor--;
	set_cursor_pos(*input);
}

/*
**	Move the cursor to the right
**
**	@param input Structure t_line
*/
void	move_cursor_right(t_line *input)
{
	if (input->cursor + 1 >= MAX_CMD_LINE || input->cursor >= input->lenght)
		return ;
	input->cursor++;
	set_cursor_pos(*input);
}

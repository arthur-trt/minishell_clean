/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor_words.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 19:44:03 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/24 17:10:43 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Moves the cursor to the beginning of the line
**
**	@param input Structure t_line
*/
void	move_cursor_to_start(t_line *input)
{
	input->cursor = 0;
	set_cursor_pos(*input);
}

/*
**	Moves the cursor to the end of the line
**
**	@param input Structure t_line
*/
void	move_cursor_to_end(t_line *input)
{
	input->cursor = input->lenght;
	set_cursor_pos(*input);
}

/*
**	Moves the cursor to the beginning of the word on the left
**
**	@param input Structure t_line
*/
void	move_cursor_left_word(t_line *input)
{
	if (input->cursor && input->line[input->cursor - 1] == ' ')
		input->cursor--;
	while (input->line[input->cursor] == ' ' && input->cursor)
		input->cursor--;
	while (input->line[input->cursor] != ' ' && input->cursor)
		input->cursor--;
	if (input->cursor)
		input->cursor++;
	set_cursor_pos(*input);
}

/*
**	Moves the cursor to the beginning of the word on the right
**
**	@param input Structure t_line
*/
void	move_cursor_right_word(t_line *input)
{
	while (input->line[input->cursor] != ' ' && input->cursor < input->lenght)
		input->cursor++;
	while (input->line[input->cursor] == ' ' && input->cursor < input->lenght)
		input->cursor++;
	set_cursor_pos(*input);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:31:34 by atrouill          #+#    #+#             */
/*   Updated: 2021/05/27 17:58:50 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Inserts a character at the cursor position
**
**	@param input Structure containing information about the typed line
**	@param c Character to insert
**
**	@return True if the insertion has been completed, false otherwise
*/
bool	insert_char(t_line *input, int c)
{
	if (input->lenght + 1 >= MAX_CMD_LINE)
		return (false);
	ft_memmove(input->line + input->cursor + 1, input->line + input->cursor,
		input->lenght - input->cursor + 1);
	input->line[input->cursor] = c;
	input->lenght++;
	input->cursor++;
	tputs(tgetstr("im", NULL), 1, &outfun);
	ft_putchar_fd(c, 0);
	tputs(tgetstr("ei", NULL), 1, &outfun);
	return (true);
}

/*
**	Delete a character at the cursor position in left direction
**
**	@param input Structure containing information about the typed line
**
**	@return True if the deletion has been completed, false otherwise
*/
bool	delete_char(t_line *input)
{
	if (input->cursor == 0)
		return (false);
	move_cursor_left(input);
	if ((size_t)input->cursor == input->lenght)
		return (false);
	ft_memmove(input->line + input->cursor, input->line + input->cursor + 1,
		input->lenght - input->cursor + 1);
	input->lenght--;
	tputs(tgetstr("cd", NULL), 0, &outfun);
	ft_putstr_fd(input->line + input->cursor, 0);
	set_cursor_pos(*input);
	return (true);
}

/*
**	Delete a character at the cursor position in right direction
**
**	@param input Structure containing information about the typed line
**
**	@return True if the deletion has been completed, false otherwise
*/
bool	delete_char_after(t_line *input)
{
	if (input->lenght + 1 >= MAX_CMD_LINE)
		return (false);
	ft_memmove(input->line + input->cursor, input->line + input->cursor + 1,
		input->lenght - input->cursor + 1);
	input->lenght--;
	tputs(tgetstr("cd", NULL), 0, &outfun);
	ft_putstr_fd(input->line + input->cursor, 0);
	set_cursor_pos(*input);
	return (true);
}

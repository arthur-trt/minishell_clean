/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_key_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:05:06 by atrouill          #+#    #+#             */
/*   Updated: 2021/05/26 13:52:38 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS
# include "minishell.h"

void	special_bonus_keys(t_line *input, int key_code)
{
	if (key_code == 127)
		delete_char(input);
	if (key_code == KEY_DC)
		delete_char_after(input);
	if (key_code == KEY_HOME)
		move_cursor_to_start(input);
	if (key_code == KEY_END)
		move_cursor_to_end(input);
	if (key_code == KEY_CTRL_LEFT)
		move_cursor_left_word(input);
	if (key_code == KEY_CTRL_RIGHT)
		move_cursor_right_word(input);
	if (key_code == KEY_CTRL_UP)
		move_cursor_prev_line(input);
	if (key_code == KEY_CTRL_DOWN)
		move_cursor_next_line(input);
}
#endif

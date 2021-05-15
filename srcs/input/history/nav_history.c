/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nav_history.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:35:25 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/27 10:38:29 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	fill_line(t_line *input, char *cmd)
{
	size_t	len;

	len = ft_strlen(cmd);
	move_cursor_to_start(input);
	tputs(tgetstr("cd", NULL), 0, &outfun);
	ft_bzero(input->line, MAX_CMD_LINE);
	ft_strlcpy(input->line, cmd, len + 1);
	input->cursor = len;
	input->lenght = len;
}

/*
**	Go through the history from the most recent to the oldest
**
**	@param input Structure t_line
**	@param hist Linked list representing the history
**
**	@return False if the operation failed, true otherwise
*/
void	history_nav_up(t_line *input, t_hist **hist)
{
	if ((*hist) != NULL)
	{
		if (input->hist_pos != 0 && (*hist)->next != NULL)
			(*hist) = (*hist)->next;
		fill_line(input, (*hist)->line);
		outfun_str(input->line);
		input->hist_pos++;
	}
}

/*
**	Go through the history from the oldest to the most recent
**
**	@param input Structure t_line
**	@param hist Linked list representing the history
**
**	@return False if the operation failed, true otherwise
*/
void	history_nav_down(t_line *input, t_hist **hist)
{
	if ((*hist) != NULL)
	{
		if ((*hist)->prev == NULL)
		{
			input->hist_pos = 0;
			fill_line(input, "");
		}
		else
		{
			(*hist) = (*hist)->prev;
			fill_line(input, (*hist)->line);
			input->hist_pos--;
		}
		outfun_str(input->line);
	}
}

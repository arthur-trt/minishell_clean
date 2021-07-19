/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 09:11:57 by atrouill          #+#    #+#             */
/*   Updated: 2021/07/08 13:53:05 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

//static void	init_struct(t_line *input)
//{
//	input->cursor_pos.row = 0;
//	input->cursor_pos.col = 0;
//	input->cursor = 0;
//	input->win_size.row = 0;
//	input->win_size.col = 0;
//	input->lenght = 0;
//	input->hist_pos = 0;
//	ft_bzero(input->line, MAX_CMD_LINE);
//}

void	sigint_input(void)
{
	ft_bzero(g_glob->input.line, MAX_CMD_LINE);
}

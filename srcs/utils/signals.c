/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:54:07 by jcueille          #+#    #+#             */
/*   Updated: 2021/11/30 13:47:01 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

extern t_glob	*g_glob;

void	quit_par_handler(int sigid)
{
	(void)sigid;
	ft_putendl_fd("Quit (core dumped)", 2);
	g_glob->ret = 131;
}

void	int_par_handler(int sigid)
{
	(void)sigid;
	ft_putchar_fd('\n', 0);
	if (g_glob->prog == 0)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	g_glob->ret = 130;
}

void	quit_child_handler(int sigid)
{
	(void)sigid;
	_exit(131);
}

void	int_child_handler(int sigid)
{
	(void)sigid;
	ft_putchar_fd('\n', 0);
	_exit(130);
}

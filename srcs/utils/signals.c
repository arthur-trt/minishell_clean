/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:54:07 by jcueille          #+#    #+#             */
/*   Updated: 2021/10/19 14:41:52 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

extern t_glob	*g_glob;

void	int_handler(void)
{
	g_glob->ret = 130;
	if (g_glob->prog == 1 && g_glob->heredocs)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		if ( g_glob->pid == 0)
			exit(130);
	}
	else if (g_glob->prog == 0)
	{
		ft_putstr_fd("\n", 0);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else
	{
		ft_putchar_fd('\n', 0);
	}
}

void	quit_handler(void)
{
	if (g_glob->prog == 1)
	{
		g_glob->ret = 131;
		kill(g_glob->pid, SIGQUIT);
		ft_putendl_fd("Quit (core dumped)", 1);
	}
}

void	sig_handler(int sigld)
{
	if (sigld == SIGQUIT)
		quit_handler();
	else if (sigld == SIGINT)
		int_handler();
}

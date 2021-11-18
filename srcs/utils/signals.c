/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:54:07 by jcueille          #+#    #+#             */
/*   Updated: 2021/11/18 10:45:50 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

extern t_glob	*g_glob;

void	int_handler(void)
{
	debug("Signal recive pid -> [%d]", g_glob->pid);
	debug("Signal recive tmp_pid -> [%d]", g_glob->tmp_pid);
	debug("Signal recive heredocs -> [%d]", g_glob->heredocs);
	g_glob->ret = 130;
	if (g_glob->tmp_pid != 0)
	{
		kill(g_glob->tmp_pid, SIGTERM);
		ft_putchar_fd('\n', 0);
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

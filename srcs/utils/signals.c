/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:54:07 by jcueille          #+#    #+#             */
/*   Updated: 2021/11/24 18:44:17 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

extern t_glob	*g_glob;

void    chld_handler(int signum)
{
    if (signum == SIGCHLD)
        puts("wait dono why");
    return ;
}


void	int_heredocs_handler(int sigid)
{
	(void)sigid;
	puts("caca");
	ft_putstr_fd("^C\n", 0);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	exit(0);
}

void	int_handler(void)
{
	int ret;
	g_glob->ret = 130;
	signal(SIGINT, sig_handler);
	if (g_glob->tmp_pid != 0)
	{
		kill(g_glob->tmp_pid, SIGTERM);
		waitpid(g_glob->tmp_pid, &ret, 0);
	}
	else if (g_glob->prog == 0)
	{
		ft_putstr_fd("^C\n", 0);
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
	signal(SIGQUIT, sig_handler);
	g_glob->ret = 131;
	ft_putendl_fd("Quit (core dumped)", 2);
	kill(g_glob->pid, SIGQUIT);
}

void	quit_child_handler(int sigid)
{
	(void)sigid;
	g_glob->ret = 131;
	signal(SIGQUIT, quit_child_handler);
	ft_putendl_fd("Quit (core dumped)", 2);
	exit(131);
}

void	sig_handler(int sigld)
{
	//debug("Signa catch : [%d] on [%d]", sigld, getpid());
	if (sigld == SIGQUIT)
		quit_handler();
	else if (sigld == SIGINT)
		int_handler();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:54:07 by jcueille          #+#    #+#             */
/*   Updated: 2021/08/30 15:39:43 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

extern t_glob	*g_glob;

void	c_handler(int sigld)
{
	(void)sigld;
	g_glob->ret = 130;
	if (g_glob->prog == 0)
	{
		ft_putchar_fd('\n', 0);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else
	{
		ft_putchar_fd('\n', 0);
	}
}

void	d_handler(int sigld)
{
	(void)sigld;
	if (g_glob->prog == 1)
	{
		g_glob->ret = 131;
		kill(g_glob->pid, SIGQUIT);
		ft_putendl_fd("Quit (core dumped)", 1);
	}
}

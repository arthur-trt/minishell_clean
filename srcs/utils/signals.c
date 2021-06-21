/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:54:07 by jcueille          #+#    #+#             */
/*   Updated: 2021/06/21 11:32:23 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include <signal.h>

extern t_glob	*g_glob;

void	c_handler(int sigld)
{
	(void)sigld;
	g_glob->ret = 130;
	if (g_glob->prog == 0)
	{
		set_term_default_mode();
		ft_putendl_fd("", 1);
		ft_prompt();
	}
}

void	d_handler(int sigld)
{
	(void)sigld;
	set_term_default_mode();
	if (g_glob->prog == 1)
	{
		g_glob->ret = 131;
		kill(g_glob->pid, SIGQUIT);
		ft_putendl_fd("Quit (core dumped)", 1);
	}
	else
		ft_putstr_fd("\b\b \b\b", 1);
}

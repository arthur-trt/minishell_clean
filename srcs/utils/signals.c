/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:54:07 by jcueille          #+#    #+#             */
/*   Updated: 2021/07/07 10:07:48 by atrouill         ###   ########.fr       */
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
		g_glob->c = 1;
		if (g_glob->in_input == true)
		{
			write(1, "\n", 1);
			sigint_input();
		}
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
}

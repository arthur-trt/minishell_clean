/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:54:07 by jcueille          #+#    #+#             */
/*   Updated: 2021/06/10 14:25:27 by jcueille         ###   ########.fr       */
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
		ft_putendl_fd("", 1);
		ft_prompt();
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
	else
		ft_putstr_fd("\b \b\b \b", 1);
}
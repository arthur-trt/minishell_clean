/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 13:21:20 by atrouill          #+#    #+#             */
/*   Updated: 2021/11/24 18:41:07 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile t_glob	*g_glob;

int	minishell(void)
{
	char	*input_user;

	g_glob->prog = 0;
	while (true)
	{
		input_user = input();
		if (!check_error(input_user))
		{
			ft_putstr_fd("minishell: syntax error\n", 2);
			g_glob->ret = 2;
		}
		else
		{
			ft_exec(input_user);
		}
		free(input_user);
	}
	free(input_user);
	return (EXIT_SUCCESS);
}

int	main(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sig_handler);
	//signal(SIGCHLD, chld_handler);
	g_glob = NULL;
	if (ft_init_gobal())
		return (EXIT_FAILURE);
	minishell();
	clear_history();
	printf("\n");
	free_glob();
	return (EXIT_SUCCESS);
}

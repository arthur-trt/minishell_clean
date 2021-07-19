/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 13:21:20 by atrouill          #+#    #+#             */
/*   Updated: 2021/07/15 13:32:41 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

t_glob	*g_glob;

int	minishell(t_hist **hist)
{
	t_lexer	*lexed;
	char	*input_user;

	g_glob->prog = 0;
	while (true)
	{
		input_user = input(hist);
		if (ft_strcmp(input_user, "exit") == 0)
			break ;
		lexed = lexer(input_user);
		//print_lexer(lexed);
		ft_exec(lexed);
		free_lexer(&lexed);
		free(input_user);
	}
	free(input_user);
	return (EXIT_SUCCESS);
}

int	main(void)
{
	t_hist	*hist;
	//struct sigaction sa;

	signal(SIGQUIT, d_handler);
	signal(SIGINT, c_handler);
    //sa.sa_flags = 0;
    //sa.sa_handler = c_handler;
    //sigfillset(&sa.sa_mask);
    //sigaction(SIGINT, &sa, NULL);
	g_glob = NULL;
	if (ft_init_gobal())
		return (EXIT_FAILURE);
	hist = construct_hist();
	minishell(&hist);
	printf("\n");
	backup_history(hist);
	free_history(&hist);
	free_glob();
	return (EXIT_SUCCESS);
}

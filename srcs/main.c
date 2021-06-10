/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 13:21:20 by atrouill          #+#    #+#             */
/*   Updated: 2021/06/09 14:57:49 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

t_glob	*g_glob;

int		minishell(t_hist **hist)
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
		print_lexer(lexed);
		ft_exec(lexed);
		free_lexer(&lexed);
		free(input_user);
	}
	free(input_user);
	return (EXIT_SUCCESS);
}

int		main(void)
{
	t_hist	*hist;

	signal(SIGQUIT, c_handler);
	signal(SIGINT, d_handler);
	g_glob = NULL;
  	if (ft_init_gobal())
		return (EXIT_FAILURE);
	hist = construct_hist();
	print_env();
	minishell(&hist);
	printf("\n");
	backup_history(hist);
	free_history(&hist);
	free_glob();
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 13:21:20 by atrouill          #+#    #+#             */
/*   Updated: 2021/08/27 15:22:56 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

t_glob	*g_glob;

int	minishell(void)
{
	t_lexer	*lexed;
	char	*input_user;

	g_glob->prog = 0;
	while (true)
	{
		input_user = input();
		if (ft_strcmp(input_user, "exit") == 0)
			break ;
		if (!check_error(input_user))
		{
			ft_putstr_fd("minishell: syntax error\n", 2);
			g_glob->ret = 2;
			input_user[0] = '\0';
		}
		else
		{
			lexed = lexer(input_user);
			ft_exec(lexed);
			free_lexer(&lexed);
		}
		free(input_user);
	}
	free(input_user);
	return (EXIT_SUCCESS);
}

int	main(void)
{
	signal(SIGQUIT, d_handler);
	signal(SIGINT, c_handler);
	g_glob = NULL;
	if (ft_init_gobal())
		return (EXIT_FAILURE);
	minishell();
	printf("\n");
	free_glob();
	return (EXIT_SUCCESS);
}

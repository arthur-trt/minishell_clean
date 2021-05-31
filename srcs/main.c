/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 13:21:20 by atrouill          #+#    #+#             */
/*   Updated: 2021/05/31 16:15:10 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <string.h>

t_glob	*g_glob;

int		minishell(t_hist **hist)
{
	t_lexer	*lexed;
	char	*input_user;
	(void)hist;
	while (true)
	{
		input_user = input(hist);
		//input_user = ft_strdup("echo lol > lol");
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

	g_glob = NULL;
  	if(ft_init_gobal())
		return (EXIT_FAILURE);
	history_path();
	hist = construct_hist();
	print_env();
	minishell(&hist);
	printf("\n");
	backup_history(hist);
	free_history(&hist);
	free_glob();
	return (EXIT_SUCCESS);

}

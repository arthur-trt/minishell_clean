/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 13:21:20 by atrouill          #+#    #+#             */
/*   Updated: 2021/05/24 13:33:50 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <string.h>

t_glob	*g_glob;

int		minishell(t_hist **hist)
{
	t_lexer	*lexed;
	char	*input_user;
	char	*path_exec;

	while (true)
	{
		input_user = input(hist);
		if (ft_strcmp(input_user, "exit") == 0)
			break ;
		lexed = lexer(input_user);
		path_exec = search_path(input_user);
		print_lexer(lexed);
		free_lexer(&lexed);
		if (path_exec != NULL)
		{
			printf("PATH FOUND : %s\n", path_exec);
			free(path_exec);
		}
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
	hist = construct_hist();
	print_env();
	minishell(&hist);
	printf("\n");
	backup_history(hist);
	free_history(&hist);
	free_glob();
	return (EXIT_SUCCESS);

}

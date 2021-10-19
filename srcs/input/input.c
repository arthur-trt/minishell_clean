/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:15:53 by atrouill          #+#    #+#             */
/*   Updated: 2021/10/19 18:29:12 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

char	*input(void)
{
	char		*prompt;
	static char	*line_read = (char *) NULL;

	if (line_read)
		line_read = (char *) NULL;
	rl_catch_signals = 0;
	prompt = ft_prompt();
	line_read = readline(prompt);
	free(prompt);
	if (line_read && *line_read)
		history_append (line_read);
	if (line_read == NULL)
	{
		ft_putstr_fd("exit\n", 0);
		line_read = ft_strdup("exit");
	}
	return (line_read);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:15:53 by atrouill          #+#    #+#             */
/*   Updated: 2021/07/26 16:42:50 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*input_heredocs(char *delimiter)
{
	t_list	*heredocs;
	char	*tmp;

	tmp = readline("> ");
	ft_lstadd_back(&heredocs, ft_lstnew(tmp));
	while (ft_strcmp(tmp, delimiter) != 0)
	{
		tmp = readline("> ");
		ft_lstadd_back(&heredocs, ft_lstnew(tmp));
	}
	return (heredocs);
}

char	*input(void)
{
	char		*prompt;
	static char	*line_read = (char *) NULL;

	if (line_read)
		line_read = (char *) NULL;
	prompt = ft_prompt();
	line_read = readline (prompt);
	free(prompt);
	if (line_read && *line_read)
		add_history (line_read);
	if (line_read == NULL)
	{
		ft_putstr_fd("exit", 0);
		line_read = ft_strdup("exit");
	}
	return (line_read);
}

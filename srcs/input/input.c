/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:15:53 by atrouill          #+#    #+#             */
/*   Updated: 2021/07/28 12:58:43 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*input_heredocs(char *delimiter)
{
	char	*heredocs;
	char	*tmp;
	size_t	len;

	tmp = readline("heredocs> ");
	heredocs = ft_strdup(tmp);
	while (ft_strcmp(tmp, delimiter) != 0)
	{
		free(tmp);
		tmp = readline("heredocs> ");
		if (ft_strcmp(tmp, delimiter) != 0)
		{
			len = ft_strlen(heredocs) + ft_strlen(tmp) + 2;
			heredocs = ft_realloc(heredocs, len);
			ft_strlcat(heredocs, "\n", len);
			ft_strlcat(heredocs, tmp, len);
		}
	}
	free(tmp);
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

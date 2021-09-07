/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:15:53 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/07 21:30:53 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

static void	*ft_realloc2(void *ptr, int size, int newsize)
{
	char	*str;
	char	*new;
	int		i;

	str = (char *)ptr;
	new = (char *)malloc(sizeof(char) * newsize + 1);
	if (!(new))
	{
		if (ptr && size != 0)
			free(ptr);
		return (NULL);
	}
	i = -1;
	while (++i < size)
		*(new + i) = *(str + i);
	while (i < newsize)
		*(new + i++) = '\0';
	if (ptr && size != 0)
		free(ptr);
	return (new);
}

char	*input_heredocs(char *delimiter)
{
	char	*heredocs;
	char	*tmp;
	size_t	len;

	tmp = readline("heredoc> ");
	heredocs = ft_strdup(tmp);
	while (tmp && ft_strcmp(tmp, delimiter) != 0)
	{
		free(tmp);
		tmp = readline("heredoc> ");
		if (tmp && ft_strcmp(tmp, delimiter) != 0)
		{
			len = ft_strlen(heredocs) + ft_strlen(tmp) + 2;
			heredocs = ft_realloc2(heredocs, ft_strlen(heredocs), len);
			ft_strlcat(heredocs, "\n", len);
			ft_strlcat(heredocs, tmp, len);
		}
	}
	len = ft_strlen(heredocs) + 2;
	heredocs = ft_realloc2(heredocs, ft_strlen(heredocs), len);
	ft_strlcat(heredocs, "\n", len);
	free(tmp);
	return (heredocs);
}

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
		ft_putstr_fd("exit", 0);
		line_read = ft_strdup("exit");
	}
	return (line_read);
}

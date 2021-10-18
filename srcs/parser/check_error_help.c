/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_help.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:56:43 by atrouill          #+#    #+#             */
/*   Updated: 2021/10/14 14:12:49 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*remove_space(char *user_input)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = malloc((ft_strlen(user_input) + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_bzero(res, ft_strlen(user_input) + 1);
	while (user_input[i])
	{
		if (user_input[i] != ' ')
		{
			res[j] = user_input[i];
			j++;
		}
		i++;
	}
	return (res);
}

bool	valid_heredocs(char	*user_input)
{
	char	*no_space;
	size_t	i;
	char	c;

	i = 0;
	no_space = remove_space(user_input);
	while (i < ft_strlen(no_space))
	{
		if (i > 0 && (no_space[i - 1] == '<' && no_space[i] == '<'))
		{
			c = no_space[i + 1];
			if (c == '\0' || c == SEMICOLON || c == PIPE || c == '<'
				|| c == '>')
			{
				free(no_space);
				return (false);
			}
		}
		i++;
	}
	free(no_space);
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_sh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:10:57 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/10 15:19:46 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	skip_quotes(char *s, char c, ssize_t *i)
{
	(*i)++;
	while (s[(*i) + 1] != '\0' && s[(*i)] != c)
		(*i)++;
	(*i)++;
}

static ssize_t	count_word(char *s, char c)
{
	ssize_t	nb_words;
	ssize_t	i;

	i = 0;
	nb_words = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\'' || s[i] == '\"')
			skip_quotes(s, s[i], &i);
		if (s[i] == c)
			nb_words++;
		if (s[i] != '\0')
			i++;
	}
	return (nb_words + 1);
}

char	**ft_split_sh(char *s, char c)
{
	ssize_t	i;
	ssize_t	j;
	ssize_t	start;
	char	**splited;

	j = 0;
	splited = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!splited)
		return (NULL);
	i = 0;
	start = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\'' || s[i] == '\"')
			skip_quotes(s, s[i], &i);
		if (s[i] == c)
		{
			splited[j++] = ft_substr(s, start, i - start);
			start = i + 1;
		}
	}
	splited[j++] = ft_substr(s, start, i - start);
	splited[j] = NULL;
	return (splited);
}

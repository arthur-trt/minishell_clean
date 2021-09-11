/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_sh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:10:57 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/11 13:50:23 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	skip_quotes(char *s, char c, size_t *i)
{
	(*i)++;
	while (s[(*i) + 1] != '\0' && s[(*i)] != c)
		(*i)++;
	(*i)++;
}

static size_t	count_word(char *s, char c)
{
	size_t	nb_words;
	size_t	i;

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

char	**dumb_norm(char *s, char c, size_t *i, size_t *j)
{
	char	**splited;

	splited = malloc(sizeof(char *) * (count_word(s, c) + 1));
	(*i) = 0;
	(*j) = 0;
	return (splited);
}

char	**ft_split_sh(char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;
	char	**splited;

	splited = dumb_norm(s, c, &i, &j);
	if (!splited)
		return (NULL);
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
		if (s[i] != '\0')
			i++;
	}
	splited[j++] = ft_substr(s, start, i - start);
	splited[j] = NULL;
	return (splited);
}

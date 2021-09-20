/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:50:51 by atrouill          #+#    #+#             */
/*   Updated: 2021/08/13 19:50:45 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	nb_words;
	size_t	i;

	nb_words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
		{
			if (!s[i + 1])
				return (nb_words);
			i++;
		}
		while (s[i] && s[i] != c)
			i++;
		nb_words++;
	}
	return (nb_words);
}

static void	*free_ret(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static char	**ft_split_helper(char const *s, char c, size_t nb_words)
{
	size_t	i;
	size_t	j;
	char	**splited;

	i = 0;
	j = 0;
	splited = malloc(sizeof(char *) * (nb_words + 1));
	if (!(splited))
		return (NULL);
	while (j < nb_words)
	{
		while (s[i] && s[i] == c)
			i++;
		s += i;
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		splited[j] = (char *)malloc(sizeof(char) * (i + 1));
		if (!(splited[j]))
			return (free_ret(splited));
		ft_strlcpy(splited[j], s, i + 1);
		j++;
	}
	splited[j] = 0;
	return (splited);
}

/*
**	Split a string each time char c is encouter
**
**	@param s String to split
**	@param c Char who trigger the split
**
**	@return An array of splitted string
*/
char	**ft_split(char const *s, char c)
{
	size_t	nb_words;

	if (!s)
		return (NULL);
	nb_words = ft_count_words(s, c);
	return (ft_split_helper(s, c, nb_words));
}

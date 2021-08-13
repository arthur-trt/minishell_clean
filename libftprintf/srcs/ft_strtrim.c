/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:26:09 by atrouill          #+#    #+#             */
/*   Updated: 2021/08/13 20:21:54 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static size_t	ft_is_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

/*
**	Allows (with malloc(3)) and returns a copy of the string
**	string 's1', without the characters specified in
**	specified in 'set' at the beginning and end of the string.
**
**	@param s1 The string to be trimmed.
**	@param set The reference set of characters to trim.
**
**	@return The trimmed string. NULL if the allocation fails.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;

	if (!s1)
		return (NULL);
	start = 0;
	while (ft_is_in_set(s1[start], set))
		start++;
	if (start >= ft_strlen(s1))
		return (ft_strdup(""));
	len = ft_strlen(s1);
	while (ft_is_in_set(s1[len - 1], set))
		len--;
	return (ft_substr(s1, start, (len - start)));
}

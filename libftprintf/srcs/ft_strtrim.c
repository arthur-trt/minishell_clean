/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:26:09 by atrouill          #+#    #+#             */
/*   Updated: 2020/04/06 18:12:46 by atrouill         ###   ########.fr       */
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

char			*ft_strtrim(char const *s1, char const *set)
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

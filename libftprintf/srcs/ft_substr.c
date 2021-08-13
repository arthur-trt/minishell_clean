/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:11:47 by atrouill          #+#    #+#             */
/*   Updated: 2021/08/13 20:23:42 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
**	Allows (with malloc(3)) and returns a string from the string 's'.
**	This new string starts at index 'start' and has maximum size 'len'.
**
**	@param s The string from which to extract the new string
**	@param start The start index of the new string in the string 's'.
**	@param len The maximum size of the new string.
**
**	@return The new string. NULL if the allocation fails.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	s2 = malloc((len + 1) * sizeof(char));
	if (!(s2))
		return (NULL);
	i = 0;
	while (i < len)
	{
		s2[i] = s[start + i];
		i++;
	}
	s2[len] = '\0';
	return (s2);
}

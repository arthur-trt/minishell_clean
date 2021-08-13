/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:11:47 by atrouill          #+#    #+#             */
/*   Updated: 2020/04/06 18:12:46 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	if (!(s2 = malloc((len + 1) * sizeof(char))))
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

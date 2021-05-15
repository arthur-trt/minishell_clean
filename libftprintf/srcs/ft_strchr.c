/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:42:09 by atrouill          #+#    #+#             */
/*   Updated: 2020/04/06 18:12:44 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s0;

	s0 = (char *)s;
	while (*s0 != '\0')
	{
		if (*s0 == (char)c)
			return (s0);
		s0++;
	}
	if (c == '\0')
		return (s0);
	return (NULL);
}

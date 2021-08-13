/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:24:52 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/21 11:56:37 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
**	Duplicate a string
**
** @param s1 String to duplicate
**
**	@return Pointer to the new string
*/
char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*s2;

	len = ft_strlen(s1);
	i = 0;
	if (!(s2 = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i <= len)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}

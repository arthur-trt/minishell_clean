/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_gnl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 20:06:09 by atrouill          #+#    #+#             */
/*   Updated: 2020/05/19 13:02:55 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char		*ft_strjoin_gnl(char **s1, char *s2)
{
	char	*res;
	size_t	len;
	size_t	i;
	size_t	j;

	len = ft_strlen(*s1) + ft_strlen(s2);
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (*s1 && (*s1)[i] != '\0')
	{
		res[j++] = (*s1)[i];
		i++;
	}
	i = 0;
	while (s2 && s2[i] != '\0')
	{
		res[j++] = s2[i];
		i++;
	}
	*s1 ? free(*s1) : NULL;
	res[j] = '\0';
	*s1 = res;
	return (res);
}

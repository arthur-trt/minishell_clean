/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_gnl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 20:06:09 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/07 19:57:02 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
**	Concatenates two strings and add the second to the first one on the same
**	memory location
**
**	@param s1 First string
**	@param s2 Seconde string
**
**	@param Pointer to the new string
*/
char	*ft_strjoin_gnl(char **s1, char *s2)
{
	char	*res;
	size_t	len;
	size_t	i;
	size_t	j;

	len = ft_strlen(*s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (*s1 && (*s1)[++i] != '\0')
		res[j++] = (*s1)[i];
	i = -1;
	while (s2 && s2[++i] != '\0')
		res[j++] = s2[i];
	if (*s1)
		free(*s1);
	res[j] = '\0';
	*s1 = res;
	return (res);
}

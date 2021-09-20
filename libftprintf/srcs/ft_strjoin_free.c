/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:52:29 by atrouill          #+#    #+#             */
/*   Updated: 2021/08/13 19:56:57 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
**	Concatenates two strings and frees the original strings
**
**	@param s1 First string
**	@param s2 Seconde string
**
**	@param Pointer to the new string
*/
char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*res;
	size_t	len;
	size_t	i;
	size_t	j;

	len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (len + 1));
	if (!(res))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		res[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		res[j++] = s2[i++];
	res[j] = '\0';
	free(s1);
	free(s2);
	return (res);
}

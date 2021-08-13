/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:48:35 by atrouill          #+#    #+#             */
/*   Updated: 2021/08/13 20:17:29 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
**	returns a pointer to the last occurrence of the character c in the string s.
**
**	@param s String s, where to search
**	@param c Char to find
**
**	@return Pointer to the corresponding character
**	or NULL if the character was not found.
*/
char	*ft_strrchr(const char *s, int c)
{
	char	*s0;
	size_t	len;

	s0 = (char *)s;
	len = ft_strlen(s0);
	if ((char)c == '\0')
		return (s0 + len);
	while (len-- > 0)
	{
		if (s0[len] == (char)c)
			return (s0 + len);
	}
	return (NULL);
}

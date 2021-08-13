/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:47:38 by atrouill          #+#    #+#             */
/*   Updated: 2021/08/13 20:15:41 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
**	Find the first substring in a length-limited string
**
**	@param haystack The string to be searched
**	@param needle The string to search for
**	@param len The maximum number of characters to search
**
**	@return If needle is an empty string, haystack is returned
**	if needle occurs nowhere in haystack, NULL is returned;
**	otherwise a pointer to the first character of the first occurrence
**	of needle is returned.
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (needle[j] != '\0' && haystack[i + j] == needle[j]
				&& i + j < len)
				j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}

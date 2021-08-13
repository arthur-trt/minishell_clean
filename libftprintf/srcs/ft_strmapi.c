/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:29:06 by atrouill          #+#    #+#             */
/*   Updated: 2021/08/13 20:10:04 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
**	Apply the 'f' function to each character of the string passed in argument
**	to create a new string a new string (with malloc(3)) resulting from the
**	successive applications of 'f'.
**
**	@param s The string to iterate on
**	@param f The function to apply to each character
**
**	@return The character string resulting from the successive applications of
**	f. Returns NULL if the allocation fails.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	i = 0;
	res = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!(res))
		return (NULL);
	while (s[i])
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}

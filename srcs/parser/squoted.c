/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squoted.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:30:48 by jcueille          #+#    #+#             */
/*   Updated: 2021/04/21 20:13:58 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftprintf/includes/libftprintf.h"


/*
**	Handles single (strong) quoted words
**	
**	@param	s the user's input
**	@param	i the position of the character on s starting one the first single quote
**	@return res string with the text inside of the quotes or NULL in case of error
*/
char	*ft_single(char *s, int *i)
{
	int		j;
	char	*res;

	j = (*i) + 1;
	while (s[j] && s[j] != '\'')
		j++;
	res = ft_substr(s, (*i) + 1, j - (*i + 1));
	(*i) = j;
	return (res);
}

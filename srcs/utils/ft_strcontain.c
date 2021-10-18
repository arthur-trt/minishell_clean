/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcontain.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:26:23 by atrouill          #+#    #+#             */
/*   Updated: 2021/10/14 10:35:29 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Return true if a string contain the char c
**
**	@param s String to test
**	@param c Char to found
**
**	@return True if found, false otherwise
*/
bool	ft_strcontain(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (true);
		i++;
	}
	return (false);
}

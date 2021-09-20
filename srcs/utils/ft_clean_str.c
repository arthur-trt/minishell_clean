/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 13:32:21 by atrouill          #+#    #+#             */
/*   Updated: 2021/06/21 15:00:49 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Remove every space, cr, return in front of string
**
**	@param str input string to clean
**
**	@return string cleaned
*/
char	*ft_clean_str(char *str)
{
	int		i;

	if (!*str)
		return (str);
	i = 0;
	while (str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == ' '))
		i++;
	return ((char *)(str + i));
}

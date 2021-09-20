/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:20:03 by atrouill          #+#    #+#             */
/*   Updated: 2021/08/13 20:18:58 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
**	Reverses the argument string in place, i.e., it swaps the ith character
**	from the beginning with the ith character from the end.
**
**	@param str String to reverse
**
**	@return Return it's argument
*/
char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	ch;

	if (!str || !*str)
		return (str);
	i = ft_strlen(str) - 1;
	j = 0;
	while (i > j)
	{
		ch = str[i];
		str[i] = str[j];
		str[j] = ch;
		i--;
		j++;
	}
	return (str);
}

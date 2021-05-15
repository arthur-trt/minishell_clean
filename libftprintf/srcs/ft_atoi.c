/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:21:12 by atrouill          #+#    #+#             */
/*   Updated: 2020/04/06 18:12:56 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static char	*ft_clean_str(const char *str)
{
	int		i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	return ((char *)(str + i));
}

int			ft_atoi(const char *str)
{
	int				neg;
	int				i;
	unsigned int	res;
	char			*clean_str;

	neg = 1;
	i = 0;
	res = 0;
	clean_str = ft_clean_str(str);
	if (clean_str[0] == '-')
	{
		i++;
		neg = -1;
	}
	if (clean_str[0] == '+')
		i++;
	while (clean_str[i] >= 48 && clean_str[i] <= 57)
	{
		res = (res * 10) + (clean_str[i] - 48);
		i++;
	}
	return ((int)(neg * res));
}

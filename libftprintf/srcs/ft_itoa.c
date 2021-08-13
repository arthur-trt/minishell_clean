/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:45:46 by atrouill          #+#    #+#             */
/*   Updated: 2021/08/13 19:37:53 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void	ft_is_neg(int *n, int *neg)
{
	if (*n < 0)
	{
		*n = *n * -1;
		*neg = 1;
	}
	else
		*neg = 0;
}

static char	*ft_itoa_helper(int len, int neg, int n)
{
	char	*res;

	res = malloc(sizeof(char) * (len + 1));
	if (!(res))
		return (NULL);
	res[len] = '\0';
	while (len--)
	{
		res[len] = n % 10 + '0';
		n = n / 10;
	}
	if (neg)
		res[0] = '-';
	return (res);
}

/*
**	Convert a integer number to a string
**
**	@param n Number to convert in string
**
**	@return Pointer on the string
*/
char	*ft_itoa(int n)
{
	char	*res;
	int		tmp_n;
	int		len;
	int		neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmp_n = n;
	len = 1;
	ft_is_neg(&n, &neg);
	tmp_n /= 10;
	while (tmp_n)
	{
		len++;
		tmp_n /= 10;
	}
	len += neg;
	return (ft_itoa_helper(len, neg, n));
}

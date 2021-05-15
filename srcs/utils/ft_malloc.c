/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:24:17 by atrouill          #+#    #+#             */
/*   Updated: 2021/01/28 14:04:34 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_malloc(size_t size)
{
	char	*ret;

	ret = malloc(size);
	if (ret == NULL)
	{
		ft_printf("Malloc failed.");
		exit (1);
	}
	return (ret);
}

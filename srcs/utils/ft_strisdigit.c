/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 00:16:35 by atrouill          #+#    #+#             */
/*   Updated: 2021/08/31 00:17:37 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_strisdigit(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (ft_isdigit(s[i]) == false)
			return (false);
	}
	return (true);
}

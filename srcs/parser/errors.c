/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:53:58 by jcueille          #+#    #+#             */
/*   Updated: 2021/05/30 15:05:56 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_parse_error(t_list *command)
{
	if (command)
	{
		ft_listclear(&command);
		printf("There's been a malloc error.\n");
	}
	return (-1);
}

int	ft_double_error(int r, t_list *command, char *res)
{
	if (res)
		free(res);
	ft_listclear(&command);
	if (r == -3)
	{
		printf("Double quotes not closed.\n");
		return (-2);
	}
	printf("There's been a malloc error.\n");
	return (-1);
}

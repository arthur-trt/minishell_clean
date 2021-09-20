/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:53:58 by jcueille          #+#    #+#             */
/*   Updated: 2021/08/18 14:14:44 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_parse_error(t_list *command)
{
	if (command)
	{
		ft_listclear(&command);
		printf("There's been a malloc error. command %s\n", command->content);
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

int	ft_command_not_found(t_list *command)
{
	if (command)
		ft_listclear(&command);
	ft_putstr_fd("Error: path or executable name incorrect.\n", 2);
	return (-2);
}

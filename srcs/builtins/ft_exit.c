/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 09:51:26 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/01 12:48:43 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_list *cmd)
{
	if (cmd->next && cmd->next->next)
	{
		ft_putendl_fd("minishell: exit: too many arguments", 2);
		exit(1);
	}
	else if (cmd->next == NULL)
	{
		exit(0);
	}
	else if (ft_strisdigit(cmd->next->content) == false)
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(cmd->next->content, 2);
		ft_putendl_fd(": numeric argument required", 2);
		exit(1);
	}
	else
		exit(ft_atoi(cmd->next->content));
}

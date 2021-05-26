/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 14:38:23 by jcueille          #+#    #+#             */
/*   Updated: 2021/05/26 10:11:20 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(t_list *cmd)
{
	t_list	*tmp;
	int		flag;

	tmp = cmd->next;
	flag = 0;
	if (tmp && !(ft_strcmp(tmp->content, "-n")))
	{
		flag = 1;
		tmp = tmp->next;
	}
	if (!(tmp))
		return (0);
	while (tmp)
	{
		ft_putstr_fd(tmp->content, 1);
		tmp = tmp->next;
		if(tmp)
			ft_putstr_fd(" ", 1);
	}
	if (!(flag))
		ft_putstr_fd("\n", 1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 14:38:23 by jcueille          #+#    #+#             */
/*   Updated: 2021/08/12 11:34:38 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_arg(t_list **tmp)
{
	size_t	i;
	int		flag;

	flag = 0;
	while ((*tmp))
	{
		i = 1;
		if ((*tmp)->content[0] == '-')
		{
			while ((*tmp)->content[i] == 'n')
				i++;
			if ((*tmp)->content[i] == '\0')
				flag = 1;
			else
				return (flag);
			(*tmp) = (*tmp)->next;
		}
		else
			return (flag);
	}
	return (flag);
}

int	ft_echo(t_list *cmd)
{
	t_list	*tmp;
	int		flag;

	tmp = cmd->next;
	flag = is_valid_arg(&tmp);
	if (!(tmp))
		return (0);
	while (tmp)
	{
		ft_putstr_fd(tmp->content, 1);
		tmp = tmp->next;
		if (tmp)
			ft_putstr_fd(" ", 1);
	}
	if (!(flag))
		ft_putstr_fd("\n", 1);
	exit(0);
}

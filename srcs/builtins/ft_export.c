/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:38:43 by jcueille          #+#    #+#             */
/*   Updated: 2021/09/06 18:08:13 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_export(t_list *cmd)
{
	t_list	*tmp;
	int		r;

	tmp = NULL;
	if (cmd != NULL)
		tmp = cmd->next;
	if (tmp)
	{
		r = export_loop(tmp);
		if (r < 0)
			return (r);
	}
	else
		ft_env();
	return (0);
}

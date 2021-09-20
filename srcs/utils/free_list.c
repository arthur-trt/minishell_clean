/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:45:00 by jcueille          #+#    #+#             */
/*   Updated: 2021/06/21 15:00:22 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	free_list(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		if (lst->content)
		{
			free(lst->content);
			lst->content = NULL;
		}
		free(lst);
		lst = tmp;
	}
	lst = NULL;
	tmp = NULL;
	return (0);
}

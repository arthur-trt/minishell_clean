/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:37:15 by atrouill          #+#    #+#             */
/*   Updated: 2021/04/26 11:38:59 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_hist(t_hist *head)
{
	t_hist	*tmp;

	tmp = head;
	while (tmp)
	{
		printf("content : %s\n", tmp->line);
		printf("len : %zu\n\n", tmp->len);
		tmp = tmp->next;
	}
}

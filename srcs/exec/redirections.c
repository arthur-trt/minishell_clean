/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:11:08 by jcueille          #+#    #+#             */
/*   Updated: 2021/05/25 16:13:37 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

extern t_glob *g_glob;

int			ft_less(t_list *tmp, int *i, int *fdin)
{
	char	*filename;

	filename = NULL;
	while (tmp && !(filename))
	{
		if ((filename = get_file_name(tmp->content, i)))
			break ;
		tmp = tmp->next;
	}
	if (filename)
	{
		*fdin = open(filename, O_RDONLY);
		return (0);
	}
	ft_putstr_fd("Error: filename not specified after rediction\n", 2);
	return (-1);
}

int			ft_reverse()
{
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 11:42:26 by jcueille          #+#    #+#             */
/*   Updated: 2021/06/04 11:51:42 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int			word_checker_bis(t_list *tmp, char **s)
{
	int		i;

	i = 0;
	while (tmp->content[i])
	{
		if (ft_ischarset(tmp->content[i], "<>"))
		{

			if (i == 0)
				*s = NULL;
			else
				*s = ft_substr(tmp->content, 0, i - 1);
			return (1);
		}
		i++;
	}
	*s = tmp->content;
	return (0);
}
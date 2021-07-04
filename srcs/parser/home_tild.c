/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home_tild.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:03:50 by jcueille          #+#    #+#             */
/*   Updated: 2021/06/21 14:53:04 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_parser.h"
#include "../libftprintf/includes/libftprintf.h"

char	*home_tild(char *res)
{
	char	*tmp;
	char	*tmp_bis;
	char	*name;

	name = ft_strdup("HOME");
	tmp_bis = NULL;
	tmp_bis = ft_search_value(name);
	if (!(tmp_bis))
		return (res);
	if (res)
		tmp = ft_strjoin(res, tmp_bis);
	else
	{
		free(res);
		return (tmp_bis);
	}
	free(res);
	return (tmp);
}

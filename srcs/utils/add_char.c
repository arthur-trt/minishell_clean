/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 10:26:37 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/23 10:27:56 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Add char to a string. The initial string will be free and replace by the
**	the new one.
**
**	@param **res Initial string, has to be malloc
**	@param c Char to add to string
*/
void	add_char(char **res, char c)
{
	size_t	len;
	char	*tmp;

	if (*res != NULL)
	{
		len = ft_strlen(*res);
		tmp = malloc((len + 2) * sizeof(char));
		ft_bzero(tmp, len + 2);
		ft_strlcpy(tmp, *res, len + 2);
		tmp[len] = c;
		free(*res);
		*res = tmp;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:28:35 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/23 12:17:31 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Free a char array obtain with ft_split
**
**	@param array Array to split
*/
void	free_split(char **array)
{
	int	i;

	i = 0;
	if (array && *array)
		while (array[i] != NULL)
		{
			if (array[i])
				free(array[i]);
			i++;
		}
	free(array);
}

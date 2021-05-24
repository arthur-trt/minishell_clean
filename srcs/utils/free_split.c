/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:28:35 by atrouill          #+#    #+#             */
/*   Updated: 2021/05/24 13:28:43 by atrouill         ###   ########.fr       */
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
	while(array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

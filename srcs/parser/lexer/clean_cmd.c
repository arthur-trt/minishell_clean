/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:45:07 by atrouill          #+#    #+#             */
/*   Updated: 2021/03/05 19:09:52 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

/*
**	Clean string used as command, remove pipe and semicolon at the begining
**
**	@param input input string to clean
**
**	@return string cleaned
*/
char	*clean_cmd(char *input)
{
	int		add;
	char	*res;
	char	*tmp;

	add = 0;
	tmp = ft_strdup(ft_clean_str(input));
	free(input);
	if (tmp[0] == SEMICOLON || tmp[0] == PIPE)
		add = 1;
	res = ft_strdup(ft_clean_str(tmp + add));
	free(tmp);
	return (res);

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outfun.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:58:45 by atrouill          #+#    #+#             */
/*   Updated: 2021/05/15 14:06:26 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Equivalent to puthcar, use for write special char by termputs
**
**	@param c Char to write on stdout
**
**	@return Return the number written
*/
int	outfun(int c)
{
	return (write(0, &c, 1));
}

int	outfun_str(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		tputs(tgetstr("im", NULL), 1, &outfun);
		outfun(s[i]);
		tputs(tgetstr("ei", NULL), 1, &outfun);
		i++;
	}
	return (ft_strlen(s));
}

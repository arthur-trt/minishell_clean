/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrerror.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:41:21 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/01 15:16:15 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Print minishell error on STDERR according to bash format :
**	"minishell: <command or user input>: <error message> <error message2>"
**	If name var is NULL, then the error message will be :
**	"minishell: <error message>"
**
**	@param name Command or user inpur
**	@param error_msg Error message
*/
void	ft_putstrerror(char *name, char *error_msg)
{
	ft_putstr_fd("minishell: ", 2);
	if (name != NULL)
	{
		ft_putstr_fd(name, 2);
		ft_putstr_fd(": ", 2);
	}
	if (error_msg != NULL)
		ft_putstr_fd(error_msg, 2);
	ft_putstr_fd("\n", 2);
}

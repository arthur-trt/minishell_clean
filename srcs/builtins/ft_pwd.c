/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 20:40:56 by jcueille          #+#    #+#             */
/*   Updated: 2021/09/06 13:34:35 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(void)
{
	char	*cwd;
	char	*pwd;
	char	buf[4096];

	pwd = search_env("PWD");
	if (pwd != NULL)
	{
		ft_putendl_fd(pwd, 1);
	}
	else
	{
		cwd = getcwd(buf, 4096);
		if (!(cwd))
		{
			ft_putstr_fd(buf, 1);
			return (-1);
		}
		ft_putstr_fd(cwd, 1);
		ft_putchar_fd('\n', 1);
	}
	return (0);
}

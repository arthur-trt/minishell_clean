/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 20:40:50 by jcueille          #+#    #+#             */
/*   Updated: 2021/03/26 15:05:56 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../../libftprintf/includes/libft.h"

int			ft_pwd(void)
{
	char	*cwd;
	char	buf[4096];

	if (!(cwd = getcwd(buf, 4096)))
	{
		ft_putstr_fd(buf, 1);
		return (-1);
	}
	ft_putstr_fd(cwd, 1);
	return (0);
}

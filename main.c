/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 09:19:37 by atrouill          #+#    #+#             */
/*   Updated: 2021/08/16 13:28:09 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <term.h>

static void	print_key(char *key)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		printf("%X ", key[i]);
		i++;
	}
}

int	main(void)
{
	char	*key_pressed;

	set_term_raw_mode();
	key_pressed = ft_str_malloc(6);
	if (key_pressed == NULL)
		return (-1);
	read(0, key_pressed, 6);
	if (*key_pressed == '\x1b')
	{
		read(0, (key_pressed + 1), 3);
	}
	if (key_pressed[3] == '\x3b')
	{
		read(0, (key_pressed + 4), 3);
	}
	set_term_default_mode();
	print_key(key_pressed);
	free(key_pressed);
	return (0);
}

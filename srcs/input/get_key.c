/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:04:05 by atrouill          #+#    #+#             */
/*   Updated: 2021/07/07 09:09:01 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>

extern t_glob	*g_glob;

/*
**	Convert the received keycodes into the code contained in the library
**	curses.h
**
**	@param key Raw code received from the terminal
**
**	@return Code corresponding to the library curses.h
*/
static int	convert_code(char *key)
{
	if (ft_memcmp(KEY_CODE_UP, key, 4) == 0)
		return (KEY_UP);
	if (ft_memcmp(KEY_CODE_DOWN, key, 4) == 0)
		return (KEY_DOWN);
	if (ft_memcmp(KEY_CODE_LEFT, key, 4) == 0)
		return (KEY_LEFT);
	if (ft_memcmp(KEY_CODE_RIGHT, key, 4) == 0)
		return (KEY_RIGHT);
	if (ft_memcmp(KEY_CODE_DEL, key, 4) == 0)
		return (KEY_DC);
	if (ft_memcmp(KEY_CODE_HOME, key, 4) == 0)
		return (KEY_HOME);
	if (ft_memcmp(KEY_CODE_END, key, 4) == 0)
		return (KEY_END);
	if (ft_memcmp(KEY_CODE_CTRL_LEFT, key, 6) == 0)
		return (KEY_CTRL_LEFT);
	if (ft_memcmp(KEY_CODE_CTRL_RIGHT, key, 6) == 0)
		return (KEY_CTRL_RIGHT);
	if (ft_memcmp(KEY_CODE_CTRL_UP, key, 6) == 0)
		return (KEY_CTRL_UP);
	if (ft_memcmp(KEY_CODE_CTRL_DOWN, key, 6) == 0)
		return (KEY_CTRL_DOWN);
	if (ft_memcmp(KEY_CODE_EOF, key, 4) == 0)
		return (KEY_EOF);
	if (ft_memcmp(KEY_CODE_EXIT_TEST, key, 4) == 0)
		return (KEY_CTRL_C);
	return (key[0]);
}

/*
**	Get the code of the current key.
**	Transforms the special codes into a code understandable by curses.h
**
**	@return Key code entered by user
*/
int	get_key(void)
{
	char	*key_pressed;
	int		key;
	int		ret;

	key_pressed = ft_str_malloc(6);
	if (key_pressed == NULL)
		return (-1);
	ret = read(0, key_pressed, 7);
	//if (*key_pressed == '\x1b')
	//{
	//	read(0, (key_pressed + 1), 3);
	//}
	//if (key_pressed[3] == '\x3b')
	//{
	//	read(0, (key_pressed + 4), 3);
	//}
	key = convert_code(key_pressed);
	free(key_pressed);
	return (key);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 09:19:37 by atrouill          #+#    #+#             */
/*   Updated: 2021/08/27 15:17:46 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minishell.h"
//#include <term.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include "inc/minishell.h"

//static void	print_key(char *key)
//{
//	int	i;

//	i = 0;
//	while (i < 6)
//	{
//		printf("%X ", key[i]);
//		i++;
//	}
//}

//int	main(void)
//{
//	char	*key_pressed;

//	set_term_raw_mode();
//	key_pressed = ft_str_malloc(6);
//	if (key_pressed == NULL)
//		return (-1);
//	read(0, key_pressed, 6);
//	if (*key_pressed == '\x1b')
//	{
//		read(0, (key_pressed + 1), 3);
//	}
//	if (key_pressed[3] == '\x3b')
//	{
//		read(0, (key_pressed + 4), 3);
//	}
//	set_term_default_mode();
//	print_key(key_pressed);
//	free(key_pressed);
//	return (0);
//}

static char	*remove_space(char *user_input)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = malloc((strlen(user_input) + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	bzero(res, strlen(user_input) + 1);
	while (user_input[i])
	{
		if (user_input[i] != ' ')
		{
			res[j] = user_input[i];
			j++;
		}
		i++;
	}
	return (res);
}

static bool	valid_token_input(char *user_input)
{
	int		i;
	char	*tmp;

	i = 1;
	tmp = remove_space(user_input);
	if (tmp[0] == PIPE || tmp[0] == SEMICOLON)
		return (false);
	while (tmp[i])
	{
		if (tmp[i] == PIPE || tmp[i] == SEMICOLON)
			if (tmp[i - 1] == PIPE || tmp[i - 1] == SEMICOLON)
				return (false);
		i++;
	}
	return (true);
}

static bool	is_reserved_char(char c)
{
	if (c == SEMICOLON || c == PIPE || c == '>' || c == '<')
		return (true);
	return (false);
}

static bool	is_redirect_char(char *s, size_t *i)
{
	if (s[(*i)] == '<' || s[(*i)] == '>')
	{
		(*i)++;
		if (s[(*i)] == '<' || s[(*i)] == '>')
			(*i)++;
		return (true);
	}
	return (false);
}

static bool	valid_redirect_input(char *user_input)
{
	int		i;
	bool	last_token;

	i = 0;
	last_token = false;
	while (i < strlen(user_input) - 2)
	{
		if (is_redirect_char(user_input, &i))
		{
			while (user_input[i] == ' ')
				i++;
			if (is_reserved_char(user_input[i]))
				return (false);
		}
		i++;
	}
	return (true);
}

static bool	check_error(char *user_input)
{
	if (!valid_token_input(user_input))
		printf("Token bad\n");
	if (!valid_redirect_input(user_input))
		printf("Redirect bad\n");
	return (true);
}

int	main(int argc, char **argv)
{
	char	*no_space;

	if (argc != 2)
		return (EXIT_FAILURE);
	check_error(argv[1]);
	return (EXIT_SUCCESS);
}

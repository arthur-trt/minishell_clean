/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:35:27 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/01 18:47:35 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

static bool	has_pipe(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '|')
			return (true);
		i++;
	}
	return (false);
}

void	ft_exec(char *user_input)
{
	int		i;
	char	**cmds;

	i = 0;
	cmds = ft_split(user_input, ';');
	g_glob->save_in = dup(0);
	g_glob->save_out = dup(1);
	while (cmds[i] != NULL)
	{
		if (has_pipe(cmds[i]))
		{
			piper(cmds[i]);
		}
		else
		{
			check_command(ft_parse(cmds[i]));
		}
		i++;
	}
	dup2(g_glob->save_in, 0);
	dup2(g_glob->save_out, 1);
	close(g_glob->save_in);
	close(g_glob->save_out);
	free(cmds);
}

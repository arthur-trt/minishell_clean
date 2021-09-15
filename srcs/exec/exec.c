/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:35:27 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/15 08:59:28 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

static bool	has_pipe(char *cmd)
{
	size_t	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\'' || cmd[i] == '\"')
			skip_quotes(cmd, cmd[i], &i);
		if (cmd[i] == '|')
			return (true);
		if (cmd[i] != '\0')
			i++;
	}
	return (false);
}

void	ft_exec(char *user_input)
{
	size_t		i;
	char	**cmds;
	t_list	*cmd_parsed;

	i = 0;
	cmds = ft_split_sh(user_input, ';');
	g_glob->save_in = dup(0);
	while (cmds[i] != NULL)
	{
		if (has_pipe(cmds[i]))
		{
			piper(cmds[i]);
		}
		else
		{
			cmd_parsed = ft_parse(cmds[i]);
			check_command(&cmd_parsed, cmds);
			free_list(cmd_parsed);
		}
		i++;
	}
	dup2(g_glob->save_in, 0);
	free_split(cmds);
}

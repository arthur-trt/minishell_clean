/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:35:27 by atrouill          #+#    #+#             */
/*   Updated: 2021/11/30 11:29:02 by atrouill         ###   ########.fr       */
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

static void	restore_fds(void)
{
	dup2(g_glob->save_in, 0);
	close(g_glob->save_in);
	dup2(g_glob->save_out, 1);
	close(g_glob->save_out);
}

void	ft_exec(char *user_input)
{
	size_t	i;
	char	**cmds;
	t_list	*cmd_parsed;
	int		fds[2];

	i = 0;
	cmds = ft_split_sh(user_input, ';');
	g_glob->save_in = dup(0);
	g_glob->save_out = dup(1);
	while (cmds[i] != NULL)
	{
		if (has_pipe(cmds[i]))
			piper(cmds[i]);
		else
		{
			cmd_parsed = ft_parse(cmds[i]);
			ft_bzero(fds, sizeof(int) * 2);
			if (cmd_parsed != NULL && fd_opener(&cmd_parsed, fds) != -1)
				check_command(&cmd_parsed, cmds);
			free_list(cmd_parsed);
		}
		i++;
	}
	restore_fds();
	free_split(cmds);
}

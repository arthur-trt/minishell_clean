/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:45:32 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/01 19:19:55 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

static int	count_childs(char *cmds)
{
	int	i;
	int	pipes;

	i = 0;
	pipes = 1;
	while (cmds[i] != '\0')
	{
		if (cmds[i] == '|')
			pipes++;
		i++;
	}
	return (pipes);
}

static void	exec_cmd_pipe(t_list *cmd, int *fds)
{
	t_exec	*exec;

	exec = exec_init(cmd);
	g_glob->heredocs = false;
	fd_opener(exec->cmds, &exec->fdin, &exec->fdtemp);
	if (exec->fdtemp)
		exec->fdout = exec->fdtemp;
	else
		exec->fdout = dup(g_glob->save_out);
	exec->fdin = fds[0];
	exec->fdout = fds[2];
	dprintf(2, "exec_cmd_pipe : %s\n", cmd->content);
	g_glob->ret = is_builtin(cmd);
	if (g_glob->ret == 127)
	{
		exec_bin(exec);
	}
	free(exec);
}

void	exec_pipe(bool first, bool last, int *fds, char *cmd)
{
	int	i;

	dprintf(2, "exec_pipe : %s\n", cmd);
	if (!fork())
	{
		if (first == false)
			dup2(fds[0], 0);
		if (last == false)
			dup2(fds[3], 1);
		i = 0;
		while (i < 4)
			close(fds[i++]);
		exec_cmd_pipe(ft_parse(cmd), fds);
		exit(g_glob->ret);
	}
}

int	check_pipe(int *fds, char *cmds)
{
	bool	first_pipe;
	bool	last_pipe;
	char	**cmd;
	int		childs;

	cmd = ft_split(cmds, '|');
	childs = 0;
	first_pipe = true;
	last_pipe = false;
	while (cmd[childs] != NULL)
	{
		printf("Check pipe childs : %d\n", childs);
		if (childs == count_childs(cmds) + 1)
			last_pipe = true;
		exec_pipe(first_pipe, last_pipe, fds, cmd[childs]);
		childs++;
		first_pipe = false;
		close(fds[0]);
		close(fds[1]);
		fds[0] = fds[2];
		fds[1] = fds[3];
		pipe(fds + 2);
	}
	free_split(cmd);
	return (childs);
}

void	piper(char *cmds)
{
	int	fds[4];
	int	childs;
	int	status;
	int	i;

	pipe(fds);
	pipe(fds + 2);
	childs = check_pipe(fds, cmds);
	while (childs-- > 0)
		waitpid(-1, &status, 0);
	if (WIFEXITED(status))
		g_glob->ret = WEXITSTATUS(status);
	i = 0;
	while (i < 4)
		close(fds[i++]);
}

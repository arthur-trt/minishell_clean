/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:45:32 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/02 09:32:14 by atrouill         ###   ########.fr       */
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

pid_t	exec_pipe(bool first, bool last, int *fds, char *cmd)
{
	int		i;
	t_list	*cmd_parsed;
	pid_t	child;

	child = fork();
	if (child == 0)
	{
		if (!first)
			dup2(fds[0], 0);
		if (!last)
			dup2(fds[3], 1);
		i = 0;
		while (i < 4)
			close(fds[i++]);
		cmd_parsed = ft_parse(cmd);
		check_command(cmd_parsed);
		free_list(cmd_parsed);
		exit(g_glob->ret);
	}
	return (child);
}

pid_t	*check_pipe(int *fds, char *cmds)
{
	bool	first_pipe;
	bool	last_pipe;
	char	**cmd;
	int		i;
	pid_t	*pid;

	cmd = ft_split(cmds, '|');
	i = 0;
	first_pipe = true;
	last_pipe = false;
	pid = malloc((count_childs(cmds) + 1) * sizeof(pid_t));
	ft_bzero(pid, (count_childs(cmds) + 1) * sizeof(pid_t));
	while (cmd[i] != NULL)
	{
		if (i + 1 == count_childs(cmds))
			last_pipe = true;
		pid[i] = exec_pipe(first_pipe, last_pipe, fds, cmd[i]);
		i++;
		first_pipe = false;
		close(fds[0]);
		close(fds[1]);
		fds[0] = fds[2];
		fds[1] = fds[3];
		pipe(fds + 2);
	}
	free_split(cmd);
	return (pid);
}

void	piper(char *cmds)
{
	int		fds[4];
	pid_t	*childs;
	int		status;
	int		i;

	pipe(fds);
	pipe(fds + 2);
	childs = check_pipe(fds, cmds);
	i = 0;
	while (childs[i] != 0)
	{
		waitpid(childs[i], &status, 0);
		i++;
	}
	free(childs);
	if (WIFEXITED(status))
		g_glob->ret = WEXITSTATUS(status);
	i = 0;
	while (i < 4)
		close(fds[i++]);
}

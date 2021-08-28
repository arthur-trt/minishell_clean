/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:14:03 by atrouill          #+#    #+#             */
/*   Updated: 2021/08/28 16:51:33 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

extern t_glob	*g_glob;

int	exec_path(t_list *cmds)
{
	char	*path;
	char	**env;
	char	**args;

	path = search_path(cmds->content);
	if (!(path))
	{
		ft_putstr_fd("Error: path or executable name incorrect.\n", 2);
		return (127);
	}
	env = env_exec_creator();
	args = argv_exec_creator(cmds);
	if (g_glob->heredocs)
		heredocs(cmds);
	if (!(env) || !(args))
	{
		ft_putstr_fd("Error: malloc failed.\n", 2);
		return (-1);
	}
	execve(path, args, env);
	return (0);
}

static t_exec	*exec_init(t_lexer *lexed)
{
	t_exec	*exec;

	exec = malloc(sizeof(*exec));
	exec->fdtemp = 0;
	exec->status = 0;
	exec->fdin = 0;
	exec->fdout = 0;
	exec->tmp = lexed;
	return (exec);
}

int	exec2(t_exec *exec)
{
	dup2(exec->fdout, 1);
	close(exec->fdout);
	if (is_builtin_no_forks(exec->cmds) == 15)
	{
		g_glob->pid = fork();
		g_glob->prog = 1;
		if (g_glob->pid == 0)
		{
			exit(is_builtin(exec->cmds));
		}
		waitpid(g_glob->pid, &exec->status, 0);
		g_glob->ret = 0;
		if (WIFEXITED(exec->status))
			g_glob->ret = WEXITSTATUS(exec->status);
		g_glob->prog = 0;
	}
	dup2(g_glob->save_in, 0);
	dup2(g_glob->save_out, 1);
	close(g_glob->save_in);
	close(g_glob->save_out);
	exec->tmp = exec->tmp->next;
	if (exec->cmds)
		free_list(exec->cmds);
	return (0);
}

void	piper(t_exec *exec)
{
	pipe(exec->fdpipe);
	exec->fdout = exec->fdpipe[1];
	exec->fdin = exec->fdpipe[0];
}

int	ft_exec(t_lexer *lexed)
{
	t_exec	*exec;

	exec = exec_init(lexed);
	while (exec->tmp)
	{
		g_glob->heredocs = false;
		g_glob->save_in = dup(0);
		g_glob->save_out = dup(1);
		exec->cmds = ft_parse(exec->tmp->cmd);
		fd_opener(exec->cmds, &exec->fdin, &exec->fdtemp);
		dup2(exec->fdin, 0);
		close(exec->fdin);
		if ((exec->tmp->next && exec->tmp->next->token == T_SEMICOLON)
			|| exec->tmp->next == NULL)
		{
			if (exec->fdtemp)
				exec->fdout = exec->fdtemp;
			else
				exec->fdout = dup(g_glob->save_out);
		}
		else
			piper(exec);
		exec2(exec);
	}
	free(exec);
	return (0);
}

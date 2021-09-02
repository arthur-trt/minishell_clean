/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:40:38 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/02 09:03:16 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

int	exec_path(t_list *cmds)
{
	char	*path;
	char	**env;
	char	**args;
	int		ret_code;

	ret_code = search_path(cmds->content, &path);
	if (ret_code != 0)
	{
		free(path);
		return (ret_code);
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
	free(path);
	return (0);
}

void	exec_bin(t_exec *exec)
{
	g_glob->pid = fork();
	g_glob->prog = 1;
	if (g_glob->pid == 0)
	{
		exit(exec_path(exec->cmds));
	}
	waitpid(-1, &exec->status, 0);
	if (WIFEXITED(exec->status))
		g_glob->ret = WEXITSTATUS(exec->status);
	g_glob->prog = 0;
}

void	check_command(t_list *cmd)
{
	t_exec	*exec;

	exec = exec_init(cmd);
	g_glob->save_in = dup(0);
	g_glob->save_out = dup(1);
	g_glob->heredocs = false;
	fd_opener(exec->cmds, &exec->fdin, &exec->fdtemp);
	dup2(exec->fdin, 0);
	close(exec->fdin);
	if (exec->fdtemp)
		exec->fdout = exec->fdtemp;
	else
		exec->fdout = dup(g_glob->save_out);
	dup2(exec->fdout, 1);
	close(exec->fdout);
	g_glob->ret = is_builtin(cmd);
	if (g_glob->ret == 127)
	{
		exec_bin(exec);
	}
	dup2(g_glob->save_in, 0);
	dup2(g_glob->save_out, 1);
	close(g_glob->save_in);
	close(g_glob->save_out);
	free(exec);
}

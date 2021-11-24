/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:40:38 by atrouill          #+#    #+#             */
/*   Updated: 2021/11/24 17:11:06 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

int	exec_path_util(void)
{
	ft_putstr_fd("Error: malloc failed.\n", 2);
	return (-1);
}

int	exec_path(t_list *cmds)
{
	char	*path;
	char	**env;
	char	**args;
	int		ret_code;

	if (cmds && cmds->content)
	{
		path = NULL;
		ret_code = search_path(cmds->content, &path);
		if (ret_code != 0)
		{
			free(path);
			return (ret_code);
		}
		env = env_exec_creator();
		args = argv_exec_creator(cmds);
		if (!(env) || !(args))
			return (exec_path_util());
		execve(path, args, env);
		free(path);
	}
	return (0);
}

void	exec_bin(t_exec *exec, char **splitted)
{
	if (exec->cmds != NULL)
	{
		g_glob->ret = is_builtin(*exec->cmds, splitted, exec);
		if (g_glob->ret == 127)
		{
			g_glob->pid = fork();
			g_glob->prog = 1;
			if (g_glob->pid == 0)
			{
				signal(SIGQUIT, quit_child_handler);
				signal(SIGINT, sig_handler);
				exit(exec_path(*exec->cmds));
			}
			waitpid(-1, &exec->status, 0);
			if (WIFEXITED(exec->status))
				g_glob->ret = WEXITSTATUS(exec->status);
			g_glob->prog = 0;
		}
	}
}

void	check_command(t_list **cmd, char **splitted)
{
	t_exec	*exec;

	exec = exec_init(cmd);
	exec_bin(exec, splitted);
	unlink(".here_doc");
	free(exec);
}

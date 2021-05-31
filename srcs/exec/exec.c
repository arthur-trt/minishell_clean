/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:14:03 by atrouill          #+#    #+#             */
/*   Updated: 2021/05/30 15:05:07 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

extern t_glob	*g_glob;

int			exec_path(t_list *cmds)
{
	char	*path;
	char	**env;
	char	**args;

	if (!(path = search_path(cmds->content)))
	{
		ft_putstr_fd("Error: path or executable name incorrect.\n", 2);
		return (-1);
	}
	printf("PATH IS %s\n", path);
	if (!(env = env_exec_creator()) || !(args = argv_exec_creator(cmds)))
	{
		ft_putstr_fd("Error: malloc failed.\n", 2);
		return (-1);
	}
	execve(path, args, env);
	return (0);
}

int			ft_exec(t_lexer *lexed)
{
	t_list	*cmds;
	t_lexer	*tmp;
	int		fdin;
	int		fdout;
	int		fdtemp;
	int		fdpipe[2];
	int		ret;

	fdtemp = 0;
	tmp = lexed;
	while (tmp)
	{
		g_glob->save_in = dup(0);
		g_glob->save_out = dup(1);
		cmds = ft_parse(tmp->cmd);
		printf_list(cmds);
		ft_redirection_check(cmds, &fdin, &fdtemp);
		dup2(fdin, 0);
		close(fdin);
		if ((tmp->next && tmp->next->token == T_SEMICOLON) || tmp->next == NULL)
		{
			if (fdtemp)
				fdout = fdtemp;
			else
				fdout = dup(g_glob->save_out);
		}
		else
		{
			pipe(fdpipe);
			fdout=fdpipe[1];
			fdin=fdpipe[0];
		}
		dup2(fdout,1);
		close(fdout);
		ret=fork();
		if(ret==0)
		{
			is_builtin(cmds);
			exit(1);
		}
		dup2(g_glob->save_in, 0);
		dup2(g_glob->save_out, 1);
		close(g_glob->save_in);
		close(g_glob->save_out);
		waitpid(ret, NULL, 0);
		tmp = tmp->next;
	}
	free_list(cmds);
	return (0);
}

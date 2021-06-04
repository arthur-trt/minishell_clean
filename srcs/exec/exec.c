/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:14:03 by atrouill          #+#    #+#             */
/*   Updated: 2021/06/04 12:05:39 by jcueille         ###   ########.fr       */
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
		return (127);
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
	fdin = 0;
	fdout = 0;
	tmp = lexed;
	while (tmp)
	{
		g_glob->save_in = dup(0);
		g_glob->save_out = dup(1);

		// printf("save_out %d save_in %d\n", g_glob->save_out, g_glob->save_in);
		
		cmds = ft_parse(tmp->cmd);
		// printf_list(cmds);
		ft_redirection_check(cmds, &fdin, &fdtemp);

		// printf("save_out2 %d save_in %d\n", g_glob->save_out, g_glob->save_in);
		// printf("fdin3 is %d\n", fdin);

		dup2(fdin, 0);

		// printf("save_out3 %d save_in %d\n", g_glob->save_out, g_glob->save_in);
		// printf("fdin4 is %d and fdout is %d\n", fdin, fdout);

		close(fdin);

		// printf("fdin5 is %d and fdout is %d\n", fdin, fdout);
		// printf("save_out3 %d\n", g_glob->save_out);
		if ((tmp->next && tmp->next->token == T_SEMICOLON) || tmp->next == NULL)
		{
			if (fdtemp)
				fdout = fdtemp;
			else
				fdout = dup(g_glob->save_out);
			// printf("fdin6 is %d and fdout is %d\n", fdin, fdout);
			// printf("save_out5 %d save_in %d\n", g_glob->save_out, g_glob->save_in);
		}
		else
		{
			pipe(fdpipe);
			fdout=fdpipe[1];
			fdin=fdpipe[0];
		}
		dup2(fdout,1);
		close(fdout);
		if (is_builtin_no_forks(cmds) == 15)
		{
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
		}
		tmp = tmp->next;
	}
	free_list(cmds);
	return (0);
}

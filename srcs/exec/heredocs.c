/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 10:56:26 by atrouill          #+#    #+#             */
/*   Updated: 2021/11/24 18:41:37 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

//static void	init_sig_handler(void)
//{
//	struct sigaction	act;

//	ft_memset(&act, 0, sizeof(act));

//	sigfillset(&act.sa_mask);
//	act.sa_handler = int_heredocs_handler;

//	sigaction(SIGINT, &act, NULL);
//	sigaction(SIGQUIT, &act, NULL);
//	sigaction(SIGTSTP, &act, NULL);
//	sigaction(SIGTERM, &act, NULL);
//	sigaction(SIGTTIN, &act, NULL);
//	sigaction(SIGTTOU, &act, NULL);
//}

static int	heredocs_helpers(t_list *cmd)
{
	char	*hd;
	int		fd;

	hd = input_heredocs(cmd);
	if (hd != NULL)
	{
		fd = open(".here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
		ft_putstr_fd(hd, fd);
		close(fd);
	}
	free(hd);
	exit(0);
}

int	heredocs(t_list	*cmd, int *fdin)
{
	int		ret;

	g_glob->prog = 1;
	g_glob->tmp_pid = fork();
	if (g_glob->tmp_pid == 0)
	{
		//init_sig_handler();
		heredocs_helpers(cmd);
	}
	waitpid(g_glob->tmp_pid, &ret, 0);
	g_glob->prog = 0;
	if (*fdin != 0)
		close(*fdin);
	(*fdin) = open(".here_doc", O_RDONLY);
	g_glob->tmp_pid = 0;
	g_glob->heredocs = false;
	if (*fdin < 0)
		return (-1);
	return (0);
}

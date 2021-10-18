/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 09:51:26 by atrouill          #+#    #+#             */
/*   Updated: 2021/10/18 14:43:43 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

static void	ft_free(t_list *cmd, t_list **old_cmds,
	char **splitted, t_exec *exec)
{
	free_glob();
	free_list(cmd);
	cmd = NULL;
	free_list(*old_cmds);
	*old_cmds = NULL;
	free_split(splitted);
	free(exec);
	exec = NULL;
}

int	ft_exit(t_list *cmd, t_list **old_cmds, char **splitted, t_exec *exec)
{
	int	exit_code;

	if (cmd->next && cmd->next->next)
	{
		ft_putendl_fd("minishell: exit: too many arguments", 2);
		return (1);
	}
	else if (cmd->next == NULL)
		exit_code = 0;
	else if (ft_strisdigit(cmd->next->content) == false)
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(cmd->next->content, 2);
		ft_putendl_fd(": numeric argument required", 2);
		exit_code = 2;
	}
	else
		exit_code = ft_atoi(cmd->next->content);
	ft_free(cmd, old_cmds, splitted, exec);
	exit(exit_code);
}

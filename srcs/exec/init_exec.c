/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:44:43 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/03 16:38:12 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_exec	*exec_init(t_list **cmd)
{
	t_exec	*exec;

	exec = malloc(sizeof(*exec));
	exec->fdtemp = 0;
	exec->status = 0;
	exec->fdin = 0;
	exec->fdout = 0;
	exec->cmds = cmd;
	return (exec);
}

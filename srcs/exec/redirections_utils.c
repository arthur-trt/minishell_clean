/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:11:16 by jcueille          #+#    #+#             */
/*   Updated: 2021/11/19 13:53:33 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

/*
*** Launches the proper function according to which type of redirection is found
*** @param t_list*tmp the link containing the string
***	on which redirection has been found
*** @param int*i The position where the redirection happens
*** @param int*fdin our input fd
*** @param int*fdout our output fd
*** @return 0 on success. <0 if failure.
*/
static int	ft_redirect(t_list *tmp, int *i, int *fdin, int *fdout)
{
	int		r;

	r = 0;
	if (tmp->content[*i] == '<' && tmp->content[*i + 1] == '<')
	{
		g_glob->heredocs = true;
		if (tmp->content[(*i) + 1])
			(*i)++;
		r = heredocs(tmp, fdin);
	}
	else if (tmp->content[*i] == '<')
		r = ft_less(tmp, i, fdin);
	else if (tmp->content[*i] == '>' && tmp->content[*i + 1] == '>')
		r = ft_append(tmp, i, fdout);
	else if (tmp->content[*i] == '>')
	{
		r = ft_more(tmp, i, fdout);
	}
	return (r);
}

/*
*** Checks if the command contains a redirection
*** @param t_list*cmds The linked list containing our command
*** @param int*fdin our input fd that we'll modify if < is found
*** @param int*fdout our outpud fd we'll modify if > or >> is found
*** @return 0 on success. < 0 if failure.
*/
int	ft_redirection_check(t_list *cmds, int *fdin, int *fdout)
{
	t_list	*tmp;
	int		i;
	int		ret;

	tmp = cmds;
	while (tmp)
	{
		i = 0;
		while (tmp && (i < (int)ft_strlen(tmp->content)))
		{
			if (ft_ischarset(tmp->content[i], "<>") && tmp->d_quote == 0
				&& tmp->esc == 0)
			{
				ret = ft_redirect(tmp, &i, fdin, fdout);
				if (ret != 0)
					return (ret);
				if (tmp)
					tmp = tmp->next;
			}
			i++;
		}
		if (tmp)
			tmp = tmp->next;
	}
	return (0);
}

int	fd_opener(t_list **cmds, int *fds)
{
	if (ft_redirection_check(*cmds, fds, fds + 1))
	{
		g_glob->ret = 1;
		return (-1);
	}
	clean_cmds(cmds);
	if (fds[0] != 0)
	{
		dup2(fds[0], 0);
		close(fds[0]);
	}
	if (fds[1] != 0)
	{
		dup2(fds[1], 1);
		close(fds[1]);
	}
	return (0);
}

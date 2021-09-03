/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:11:16 by jcueille          #+#    #+#             */
/*   Updated: 2021/09/04 00:44:18 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

bool	ft_ischarset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (true);
		i++;
	}
	return (false);
}

/*
***	Gets the file name for the redirection
*** @param char*s the string containing the filename we want to parse
*** @param int*i our current position on the string
*** @return The char *filename if present or NULL if no filename is specified.
*/
char	*get_file_name(char *s, int *i)
{
	int		j;
	char	*filename;

	filename = NULL;
	while (s[*i] == ' ')
		(*i)++;
	j = *i;
	while (s[j] && (ft_isalnum(s[j]) || s[j] == '_'
			|| s[j] == '-' || s[j] == '.' || s[j] == ' '))
		j++;
	if (*i != j)
		filename = ft_substr(s, *i, j - *i);
	return (filename);
}

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
	}
	else if (tmp->content[*i] == '<')
		r = ft_less(tmp, i, fdin);
	else if (tmp->content[*i] == '>' && tmp->content[*i + 1] == '>')
		r = ft_append(tmp, i, fdout);
	else if (tmp->content[*i] == '>')
	{
		r = ft_more(tmp, i, fdout);
		if (g_glob->heredocs)
		{
			g_glob->tmp_fdout = *fdout;
			*fdout = 0;
		}
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
		while (tmp->content[i])
		{
			if (ft_ischarset(tmp->content[i], "<>") && tmp->d_quote == 0
				&& tmp->esc == 0)
			{
				ret = ft_redirect(tmp, &i, fdin, fdout);
				if (ret != 0)
					return (ret);
				tmp = tmp->next;
			}
			i++;
		}
		tmp = tmp->next;
	}
	return (0);
}

static bool	is_redirect(char *s)
{
	if (ft_strcmp(s, ">>") == 0
		|| ft_strcmp(s, ">") == 0
		|| ft_strcmp(s, "<") == 0)
		return (true);
	return (false);
}

static void	remove_redirect(t_list **cmds)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *cmds;
	if (tmp != NULL && is_redirect(tmp->content))
	{
		*cmds = tmp->next->next;
	}
	else
	{
		while (tmp != NULL && is_redirect(tmp->content) == false)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		if (tmp == NULL)
			return ;
		prev->next = tmp->next->next;
	}
	free(tmp->next->content);
	tmp->next->content = NULL;
	free(tmp->content);
	tmp->content = NULL;
	free(tmp->next);
	tmp->next = NULL;
	free(tmp);
	tmp = NULL;
}

int	fd_opener(t_list **cmds, int *fdin, int *fdout)
{
	if (ft_redirection_check(*cmds, fdin, fdout))
	{
		g_glob->ret = 1;
		return (-1);
	}
	remove_redirect(cmds);
	if (!(*fdout))
		*fdout = dup(g_glob->save_out);
	if (!(*fdin))
		*fdin = dup(g_glob->save_in);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:11:16 by jcueille          #+#    #+#             */
/*   Updated: 2021/07/23 11:54:57 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

int	ft_ischarset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
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
			|| s[j] == '-' || s[j] == '.'))
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
	if (tmp->content[*i] == '<')
		r = ft_less(tmp, i, fdin);
	else if (tmp->content[*i] == '>' && tmp->content[*i + 1] == '>')
		r = ft_append(tmp, i, fdout);
	else if (tmp->content[*i] == '>')
		r = ft_more(tmp, i, fdout);
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

	tmp = cmds;
	while (tmp)
	{
		i = 0;
		while (tmp->content[i])
		{
			if (ft_ischarset(tmp->content[i], "<>"))
				return (ft_redirect(tmp, &i, fdin, fdout));
			i++;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	fd_opener(t_list *cmds, int *fdin, int *fdout)
{
	if (ft_redirection_check(cmds, fdin, fdout))
		return (-1);
	if (!(*fdout))
		*fdout = dup(g_glob->save_out);
	if (!(*fdin))
		*fdin = dup(g_glob->save_in);
	return (0);
}

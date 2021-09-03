/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:11:08 by jcueille          #+#    #+#             */
/*   Updated: 2021/09/04 00:37:16 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

/*
*** if input redirection detected opens a fd in read only
*** @param t_list*tmp a struct containing the string we're looking at
*** @param int*i our position on the string
*** @param int*fdin the fd we're gonna open
*** @return 0 if success. < 0 if failure
*/
int	ft_less(t_list *tmp, int *i, int *fdin)
{
	char	*filename;

	filename = NULL;
	while (tmp && !(filename))
	{
		filename = get_file_name(tmp->content, i);
		if ((filename))
			break ;
		*i = 0;
		tmp = tmp->next;
	}
	if (filename)
	{
		*fdin = open(filename, O_RDONLY);
		if (*fdin < 0)
		{
			ft_putstrerror(filename, strerror(errno));
			free(filename);
			return (-1);
		}
		free(filename);
		return (0);
	}
	ft_putstr_fd("Error: filename not specified after rediction\n", 2);
	return (-1);
}

/*
*** if output redirection detected opens a fd either write only or append
*** @param t_list*tmp a struct containing the string we're looking at
*** @param int*i our position on the string
*** @param int*fdout the fd we're gonna open
*** @return 0 if success. < 0 if failure
*/
int	ft_more(t_list *tmp, int *i, int *fdout)
{
	char	*filename;

	if (tmp->content[(*i) + 1])
		(*i)++;
	else
	{
		*i = 0;
		tmp = tmp->next;
	}
	filename = NULL;
	while (tmp && !(filename))
	{
		filename = get_file_name(tmp->content, i);
		if ((filename))
			break ;
		tmp = tmp->next;
	}
	if (filename)
	{
		*fdout = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
		free(filename);
		return (0);
	}
	ft_putstr_fd("Error: filename not specified after rediction\n", 2);
	return (-1);
}

static int	file_opener(char *filename, int *fdout)
{
	*fdout = open(filename, O_RDWR | O_APPEND | O_CREAT, 0644);
	free(filename);
	return (0);
}

int	ft_append(t_list *tmp, int *i, int *fdout)
{
	char		*filename;

	(*i)++;
	if (tmp->content[(*i) + 1])
		(*i)++;
	else
	{
		*i = 0;
		tmp = tmp->next;
	}
	filename = NULL;
	while (tmp && !(filename))
	{
		filename = get_file_name(tmp->content, i);
		if ((filename))
			break ;
		tmp = tmp->next;
	}
	if (filename)
		return (file_opener(filename, fdout));
	ft_putstr_fd("Error: filename not specified after redirection\n", 2);
	return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:26:47 by atrouill          #+#    #+#             */
/*   Updated: 2021/11/16 15:08:25 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob	*g_glob;

static char	*find_filename(t_list *tmp, int *i)
{
	char	*filename;

	filename = NULL;
	while (tmp && !(filename))
	{
		if (ft_strcontain(tmp->content, '>') == false
			&& ft_strcontain(tmp->content, '<') == false)
		{
			filename = get_file_name(tmp->content, i);
			if ((filename))
				break ;
			*i = 0;
		}
		tmp = tmp->next;
	}
	return (filename);
}

/*
**	If input redirection detected open a fd in read only
**
**	@param	tmp		A struct containaing parsed input
**	@param	*i		Our position in the string
**	@param	*fdin	The fd we are gonna open
**
**	@return	0 if succed, < 0 if failur
*/
int	ft_less(t_list *tmp, int *i, int *fdin)
{
	char	*filename;

	filename = find_filename(tmp, i);
	if (filename != NULL)
	{
		if (*fdin != 0)
			close(*fdin);
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
	ft_putstrerror("Parsing", "Filename not specified after redirection");
	return (-1);
}

/*
**	If output redirection detected open a fd in write only
**
**	@param	tmp		A struct containaing parsed input
**	@param	*i		Our position in the string
**	@param	*fdout	The fd we are gonna open
**
**	@return	0 if succed, < 0 if failur
*/
int	ft_more(t_list *tmp, int *i, int *fdout)
{
	char	*filename;

	filename = find_filename(tmp, i);
	if (filename != NULL)
	{
		if ((*fdout) != 0)
			close(*fdout);
		*fdout = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (*fdout < 0)
		{
			ft_putstrerror(filename, strerror(errno));
			free(filename);
			return (-1);
		}
		free(filename);
		return (0);
	}
	ft_putstrerror("Parsing", "Filename not specified after redirection");
	return (-1);
}

/*
**	If input redirection detected open a fd in write only and in append mode
**
**	@param	tmp		A struct containaing parsed input
**	@param	*i		Our position in the string
**	@param	*fdin	The fd we are gonna open
**
**	@return	0 if succed, < 0 if failur
*/
int	ft_append(t_list *tmp, int *i, int *fdout)
{
	char	*filename;

	filename = find_filename(tmp, i);
	if (filename != NULL)
	{
		if ((*fdout) != 0)
			close(*fdout);
		*fdout = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0644);
		if (*fdout < 0)
		{
			ft_putstrerror(filename, strerror(errno));
			free(filename);
			return (-1);
		}
		free(filename);
		return (0);
	}
	ft_putstrerror("Parsing", "Filename not specified after redirection");
	return (-1);
}

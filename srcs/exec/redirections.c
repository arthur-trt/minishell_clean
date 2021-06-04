
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:11:08 by jcueille          #+#    #+#             */
/*   Updated: 2021/05/25 16:13:37 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob *g_glob;


/*
*** if input redirection detected opens a fd in read only
*** @param t_list*tmp a struct containing the string we're looking at
*** @param int*i our position on the string
*** @param int*fdin the fd we're gonna open
*** @return 0 if success. < 0 if failure
*/
int			ft_less(t_list *tmp, int *i, int *fdin)
{
	char	*filename;

	filename = NULL;

	while (tmp && !(filename))
	{
		if ((filename = get_file_name(tmp->content, i)))
			break ;
		*i = 0;
		tmp = tmp->next;
	}
	if (filename)
	{
		if (!(*fdin = open(filename, O_RDONLY)))
			printf("error opening file\n");
		printf("fdin is %d\n", *fdin);
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
int			ft_more(t_list *tmp, int *i, int *fdout)
{
	printf("Entering ft_more\n");
	char	*filename;
	int		append;

	append = 0;
	if (tmp->content[(*i) + 1] == '>')
	{
		(*i)++;
		append++;
	}
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
		if ((filename = get_file_name(tmp->content, i)))
			break ;
		tmp = tmp->next;
	}
	if (filename)
	{
		if (append == 0)
		{
			*fdout = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
			printf("fdout is : %d\n", *fdout);
			
		}
		else
			*fdout = open(filename, O_RDWR | O_APPEND | O_CREAT, 0644);
		free(filename);
		return (0);
	}
	ft_putstr_fd("Error: filename not specified after rediction\n", 2);
	return (-1);
}

int			ft_reverse()
{
	return (0);
}

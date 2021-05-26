/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:11:16 by jcueille          #+#    #+#             */
/*   Updated: 2021/05/26 10:04:31 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_glob *g_glob;

int			ft_ischarset(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*get_file_name(char *s, int *i)
{
	int 	j;
	char	*filename;

	filename = NULL;
	while (s[*i] == ' ')
		(*i)++;
	j = *i;
	while (s[j] && (ft_isalnum(s[j]) || s[j] == '_' || s[j] == '-' || s[j] == '.'))
		j++;
	if (*i != j)
		filename = ft_substr(s, *i, j - *i);
	return (filename);
}

static int	ft_redirect(t_list *tmp, int *i, int *fdin, int *fdout)
{
	int		r;

	r = 0;
	(void)fdout;
	if ((char)tmp->content[*i] == '<' && tmp->content[*i] == '>' )
		r = ft_reverse();
	else if (tmp->content[*i] == '<')
		r = ft_less(tmp, i, fdin);
	// else
		// r = ft_more();
	return (r);
}

int			ft_redirection_check(t_list *cmds, int *fdin, int *fdout)
{
	t_list	*tmp;
	int		i;

	tmp = cmds;
	while (tmp)
	{
		i = -1;
		while (tmp->content[++i])
		{
			if (ft_ischarset(tmp->content[i], "<>"))
				ft_redirect(tmp, &i, fdin, fdout);
		}
		tmp = tmp->next;
	}
	if (!(*fdout))
		*fdout = dup(g_glob->save_out);
	if (!(*fdin))
		*fdin = dup(g_glob->save_in);
	return (0);
}

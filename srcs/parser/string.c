/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:29:08 by jcueille          #+#    #+#             */
/*   Updated: 2021/09/20 12:12:31 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

extern t_glob	*g_glob;

char	*ft_apply_str(char *s, int *i, char *res)
{
	char	*tmp;
	char	*tmp_bis;

	tmp_bis = NULL;
	tmp = ft_string(s, i);
	if (!(res) && tmp)
		tmp_bis = ft_strdup(tmp);
	else if (res && tmp)
		tmp_bis = ft_strjoin(res, tmp);
	free(res);
	res = NULL;
	free(tmp);
	return (tmp_bis);
}

int	get_len(char *s, int i)
{
	int	j;

	j = 0;
	while (s[i] && s[i] != ' ' && s[i] != '\"' && s[i] != '\''
		&& s[i] != '>' && s[i] != '<')
	{
		if (s[i] == '\\')
		{
			i++;
			if (!(s[i]))
				break ;
		}
		j++;
		i++;
	}
	return (j);
}

char	*ft_string(char *s, int *i)
{
	int		j;
	char	*res;

	j = 0;
	if (s[*i] == '\\' && (s[*i + 1] == '>' || s[*i + 1] == '<'))
	{
		(*i)++;
		g_glob->esc = true;
		return (ft_strdup(&s[*i]));
	}
	res = malloc((get_len(s, *i) + 1) * sizeof(char));
	while (s[*i] && s[*i] != ' ' && s[*i] != '\"' && s[*i] != '\''
		&& s[*i] != '<' && s[*i] != '>')
	{
		if (s[*i] == '\\')
			(*i)++;
		if (!(s[*i]))
			break ;
		res[j] = s[*i];
		j++;
		(*i)++;
	}
	res[j] = '\0';
	(*i)--;
	return (res);
}

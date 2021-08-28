/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:29:08 by jcueille          #+#    #+#             */
/*   Updated: 2021/08/27 22:21:03 by jcueille         ###   ########.fr       */
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
	while (s[i] && s[i] != ' ' && s[i] != '\"' && s[i] != '\'' && s[i] != '$')
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

/*
**	Handles non quoted characters
**	
**	@param	s user's input string
**	@param	i the position of the escape character on s
**	@return res the parsed text
*/
// char	*ft_string(char *s, int *i)
// {
// 	int		j;
// 	char	*res;

// 	j = *i;
// 	res = NULL;
// 	while (s[j] && s[j] != ' ' && s[j] != '\"' && s[j] != '\'' && s[j] != '$')
// 	{
// 		if (s[j] == '\\')
// 		{
// 			s = ft_remove_char(s, j);
// 			//j--;
// 		}
// 		j++;
// 	}
// 	res = ft_substr(s, *i, j - *i);
// 	(*i) = j - 1;
// 	return (res);
// }

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
	res = malloc(get_len(s, *i) * sizeof(char));
	while (s[*i] && s[*i] != ' '
		&& s[*i] != '\"' && s[*i] != '\'' && s[*i] != '$')
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:31:33 by jcueille          #+#    #+#             */
/*   Updated: 2021/09/09 13:56:08 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_parser.h"
#include "../libftprintf/includes/libftprintf.h"

extern t_glob	*g_glob;

/*
**	Applies a function  for single quotes and strings
**
**	@param	s the user's input
**	@param	i the position of the character on s
**	@param	f the function we'll apply to parse s
**	@param	res a buffer that may contain previously parsed text that we will
**	combine with the f's return value
**	@return tmp_bis a string containing the parsed text
*/
char	*ft_apply(char *s, int *i, char *(*f)(char *s, int *i), char *res)
{
	char	*tmp;
	char	*tmp_bis;

	tmp_bis = NULL;
	tmp = (*f)(s, i);
	if (!(res) && tmp)
		tmp_bis = ft_strdup(tmp);
	else if (res && tmp)
		tmp_bis = ft_strjoin(res, tmp);
	free(res);
	res = NULL;
	free(tmp);
	return (tmp_bis);
}

/*
**	Applies a function  for double quotes
**
**	@param	s the user's input
**	@param	i the position of the character on s
**	@param	f the function we'll apply to parse s
**	@param	res a buffer that may contain previously parsed text that we will
**	combine with the f's return value
**	@return r = 0 if success r < 0 if error
*/
int	ft_apply_double(char *s, int *i,
	char *(*f)(char *s, int *i, int *r), char **res)
{
	char	*tmp;
	char	*tmp_bis;
	int		r;

	r = 0;
	tmp_bis = NULL;
	tmp = (*f)(s, i, &r);
	if (!(*res) && tmp)
		tmp_bis = ft_strdup(tmp);
	else if (*res && tmp)
		tmp_bis = ft_strjoin(*res, tmp);
	free(*res);
	*res = NULL;
	free(tmp);
	*res = tmp_bis;
	return (r);
}

int	ischarset(char c, char *s)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

char	*remove_bad_var(char *s, int *i, char *res)
{
	int		k;

	k = *i;
	while (s[++k] && !(ischarset(s[k], "$\"\'~\\ ")))
		(*i)++;
	if (res)
		return (res);
	return (NULL);
}

/*
**	Applies a function  for variable expansion
**
**	@param	s the user's input
**	@param	i the position of the character on s
**	@param	res a buffer that may contain previously parsed text that we will
**	combine with the f's return value
**	@return tmp a string containing the parsed text
*/
char	*ft_apply_var(char *s, int *i, char *res, int *r)
{
	char	*tmp;
	char	*tmp_bis;

	tmp_bis = NULL;
	tmp_bis = ft_search_var(s, i, 0);
	if (!(tmp_bis))
	{
		*r = 0;
		if (res)
			return (res);
		tmp = ft_strdup("");
		return (tmp);
	}
	g_glob->expanded = true;
	if (res)
		tmp = ft_strjoin(res, tmp_bis);
	else
		return (tmp_bis);
	free(res);
	return (tmp);
}

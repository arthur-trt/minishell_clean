/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:31:33 by jcueille          #+#    #+#             */
/*   Updated: 2021/05/15 12:39:11 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_parser.h"
#include "../libftprintf/includes/libftprintf.h"

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

/*
**	Applies a function  for variable expansion
**
**	@param	s the user's input
**	@param	i the position of the character on s
**	@param	res a buffer that may contain previously parsed text that we will
**	combine with the f's return value
**	@return tmp a string containing the parsed text
*/
char	*ft_apply_var(char *s, int *i, char *res)
{
	char	*tmp;
	char	*tmp_bis;
	int		inc;

	tmp_bis = NULL;
	tmp_bis = ft_search_var(s, &inc, i);
	if (!(tmp_bis))
		return (res);
	if (res)
		tmp = ft_strjoin(res, tmp_bis);
	else
	{
		free(res);
		return (tmp_bis);
	}
	free(res);
	return (tmp);
}

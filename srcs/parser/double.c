/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:03:49 by jcueille          #+#    #+#             */
/*   Updated: 2021/09/06 16:49:01 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_parser.h"
#include "../libftprintf/includes/libftprintf.h"

/*
**	Allocates space for a concatenated string
**
**	@param	list the list to concatenate
**	@param	len the total size of all the strings contained in list
**	@return tmp_bis a string containing the parsed text
*/
char	*ft_alloc_concat(t_list *list, int len)
{
	char	*res;

	res = ft_calloc(len + 1, sizeof(char));
	if (res == NULL)
	{
		ft_listclear(&list);
		return (NULL);
	}
	return (res);
}

/*
**	Concatenates all the strings of list in a single char*
**
**	@param	list the list to concatenate
**	@param	len the total size of all the strings contained in list
**	@return res the concatened strings, NULL if error
*/
char	*ft_concat(t_list *list, int len)
{
	t_list	*tmp;
	char	*res;
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	res = ft_alloc_concat(list, len);
	if (res == NULL)
		return (NULL);
	tmp = list;
	while (tmp)
	{
		ptr = tmp->content;
		j = 0;
		while (ptr[j])
		{
			res[i] = ptr[j];
			i++;
			j++;
		}
		tmp = tmp->next;
	}
	ft_listclear(&list);
	return (res);
}

/*
**	Parses the inside of double quotes
**
**	@param	s the user's input
**	@param	i the position of the character on s
**	@param	len the total length of parsed text
**	@param	list the text that's been parsed so far
**	@return r = 0 success r < 0 error
*/
static int	ft_check_double(char *s, int *i, int *len, t_list **list)
{
	int		r;

	while (s[*i] && s[*i] != '\"')
	{
		if (s[*i] == '$')
			r = ft_dollar(s, i, list, len);
		else if (s[*i] == '\\' && (s[*i + 1] && (s[*i + 1] == '"' || s[*i + 1] == '$'|| s[*i + 1] == '\'')))	
			r = ft_quoted_esc(s, i, list, len);
		else
			r = ft_quoted_str(s, i, list, len);
		if (r)
		{
			ft_listclear(list);
			return (r);
		}
		(*i)++;
	}
	return (r);
}

/*
**	Parses double quoted strings
**
**	@param	s the user's input
**	@param	i the position of the character on s
**	@param	r an int containing error value
**	@return res a string containing the parsed text
*/
char	*ft_double(char *s, int *i, int *r)
{
	t_list	*list;
	char	*res;
	int		len;

	len = 0;
	list = NULL;
	res = NULL;
	(*i)++;
	(*r) = ft_check_double(s, i, &len, &list);
	if ((*r) != 0)
		return (NULL);
	if (s[*i] != '\"')
	{
		(*r) = -3;
		ft_listclear(&list);
	}
	if (list)
		res = ft_concat(list, len);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:31:24 by jcueille          #+#    #+#             */
/*   Updated: 2021/08/26 16:20:24 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftprintf/includes/libftprintf.h"
#include <stdio.h>
/*
**	Free a linked list and its content
**
**	@param	lst the linked list to free
**	@return void
*/
void	ft_listclear(t_list **lst)
{
	t_list	*nxt;
	t_list	*tmp;

	if (*lst)
	{
		tmp = *lst;
		while (tmp)
		{
			nxt = (tmp)->next;
			free(tmp->content);
			tmp->content = NULL;
			free(tmp);
			tmp = nxt;
		}
		*lst = NULL;
	}
}

/*
**	Removes a single char from a string
**
**	@param	s user's input string
**	@param	i the position of the current character on s
**	@return void
*/
// char	*ft_remove_char(char **s, int i)
// {
// 	char	*res;
// 	int		j;

// 	printf("%zu\n", ft_strlen(*s));
// 	res = malloc((int)ft_strlen(*s) * sizeof(char) + 1);
// 	if (res == NULL)
// 		return (*s);
// 	j = -1;
// 	while (++j < i)
// 		res[j] = s[0][j];
// 	i = j;
// 	while (s[0][++j])
// 	{
// 		res[i] = s[0][j];
// 		i++;
// 	}
// 	res[j - 1] = '\0';
// 	if (*s)
// 		free(*s);
// 	return (res);
// 	//s[0] = ft_strdup(res);
// 	//s = ft_strdup(res);
// 	//free(res);
// }

char	*ft_remove_char(char *s, int i)
{
	char	*ret;
	int		j;

	printf("%zu\n", ft_strlen(s));
	ret = malloc((int)ft_strlen(s) * sizeof(char) + 1);
	if (ret == NULL)
		return s;
	j = -1;
	while (++j < i)
		ret[j] = s[j];
	i = j;
	while (s[++j])
	{
		ret[i] = s[j];
		i++;
	}
	ret[j - 1] = '\0';
	return (ret);
	//if (s)
	//	free(s);
	//s = ret;
	//s = ft_strdup(res);
	//free(res);
}
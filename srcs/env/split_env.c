/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:33:56 by atrouill          #+#    #+#             */
/*   Updated: 2021/06/20 20:06:33 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	obtain_key_len(char const *s)
{
	size_t	len;

	len = 0;
	while (s && s[len] != '=')
	{
		len++;
	}
	return (len);
}

char	**ft_split_env(char const *s)
{
	char	**splited;
	size_t	key_len;

	if (!s)
		return (NULL);
	splited = malloc(sizeof(char *) * 2);
	if (splited == NULL)
		return (NULL);
	key_len = obtain_key_len(s);
	splited[0] = (char *)malloc(sizeof(char) * (key_len + 1));
	splited[1] = (char *)malloc(sizeof(char) * (ft_strlen(s) - key_len + 1));
	if (splited[1] == NULL || splited[0] == NULL)
		return (NULL);
	ft_strlcpy(splited[0], s, key_len + 1);
	ft_strlcpy(splited[1], s + key_len + 1, (ft_strlen(s) - key_len + 1));
	return (splited);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 21:06:10 by atrouill          #+#    #+#             */
/*   Updated: 2020/04/06 18:14:27 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_parsing	*init_parsing_struct(t_parsing *parsed)
{
	if (!(parsed = malloc(sizeof(t_parsing))))
		return (NULL);
	parsed->min_width = 0;
	parsed->precision = 0;
	parsed->flags = 0;
	parsed->conv = 0;
	return (parsed);
}

int			is_converter(char c)
{
	char	*converter;

	converter = "cspdiuxX%";
	while (*converter)
	{
		if (*converter == c)
			return (1);
		converter++;
	}
	return (0);
}

char		*add_char_to_str(char *str, char c)
{
	char	*res;
	int		len;

	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	if ((res = malloc(sizeof(char) * (len + 2))) == NULL)
		return (NULL);
	ft_memcpy(res + 1, str, len);
	res[len + 1] = '\0';
	res[0] = c;
	free(str);
	return (res);
}

char		*conv_to_hex(long nbr, char *hex)
{
	char	*res;

	if ((res = ft_strdup("")) == NULL)
		return (NULL);
	if (nbr == 0)
		if ((res = add_char_to_str(res, '0')) == NULL)
			return (NULL);
	while (nbr > 0)
	{
		if ((res = add_char_to_str(res, hex[nbr % 16])) == NULL)
			return (NULL);
		nbr /= 16;
	}
	return (res);
}

int			conv_is_num(short conv)
{
	if ((conv & CONV_INT) != 0)
		return (1);
	if ((conv & CONV_UNSIGNED) != 0)
		return (1);
	if ((conv & CONV_HEX) != 0)
		return (1);
	if ((conv & CONV_HEX_MAJ) != 0)
		return (1);
	if ((conv & CONV_PTR) != 0)
		return (1);
	return (0);
}

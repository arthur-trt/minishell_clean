/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:29:21 by atrouill          #+#    #+#             */
/*   Updated: 2021/05/25 11:12:33 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_UTILS_H
# define SH_UTILS_H

# include "minishell.h"

char	*ft_clean_str(char *str);
char	*ft_str_malloc(size_t size);
char	*ft_clean_str(char *str);

void	free_split(char **array);

void	c_handler(int sigld);
void	d_handler(int sigld);

void	ft_prompt(void);

void	*ft_malloc(size_t size);
#endif

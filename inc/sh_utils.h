/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:29:21 by atrouill          #+#    #+#             */
/*   Updated: 2021/08/31 00:17:44 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_UTILS_H
# define SH_UTILS_H

# include "minishell.h"

char	*ft_clean_str(char *str);
char	*ft_str_malloc(size_t size);
char	*ft_clean_str(char *str);

void	free_split(char **array);
int		free_list(t_list *lst);

char	*clean_path(char *path);

void	c_handler(int sigld);
void	d_handler(int sigld);

bool	can_exec(char *path);

bool	ft_strisdigit(char *s);

#endif

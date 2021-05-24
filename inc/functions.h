/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:29:21 by atrouill          #+#    #+#             */
/*   Updated: 2021/05/24 14:15:24 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "minishell.h"

void	*ft_malloc(size_t size);
void	init_env_elem(t_env *env);
void	add_env(char *key, char *value);
int		ft_init_gobal(void);
char	*ft_clean_str(char *str);

int		ft_modify_value(char *key, char *new_value);
void	free_glob(void);
void	ft_prompt(void);

void	c_handler(int sigld);
void	d_handler(int sigld);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 15:14:24 by atrouill          #+#    #+#             */
/*   Updated: 2021/05/15 15:15:44 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_ENV_H
# define SH_ENV_H

void	free_glob(void);
void	add_env(char *key, char *value);
int		ft_init_gobal(void);
int		ft_modify_value(char *key, char *new_value);
char	*search_env(char *key);

#endif

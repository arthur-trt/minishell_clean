/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtins.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:40:55 by jcueille          #+#    #+#             */
/*   Updated: 2021/06/21 09:52:02 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_BUILTINS_H
# define SH_BUILTINS_H

int		ft_export(t_list *cmd);
int		ft_unset(t_list *cmd);
int		ft_echo(t_list *cmd);
int		ft_env(void);
int		ft_pwd(void);
int		ft_cd(t_list *cmd);
void	ft_exit(void);

int		ft_check_varname(char *s);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtins.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:40:55 by jcueille          #+#    #+#             */
/*   Updated: 2021/11/19 15:29:06 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_BUILTINS_H
# define SH_BUILTINS_H

# include "sh_exec.h"

int		ft_export(t_list *cmd);
int		ft_unset(t_list *cmd);
int		ft_echo(t_list *cmd);
int		ft_env(void);
int		ft_pwd(void);
int		ft_cd(t_list *cmd);
int		ft_exit(t_list *cmds, t_list **old_cmds, char **splitted, t_exec *exec);

int		export_loop(t_list *tmp);
int		ft_check_varname(char *s);
bool	check_var_name(char *var);
char	*search_cdpath(char *dir);

#endif

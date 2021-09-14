/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtins.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:40:55 by jcueille          #+#    #+#             */
/*   Updated: 2021/09/14 14:59:53 by jcueille         ###   ########.fr       */
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
void	ft_exit(t_list *cmds, t_list **old_cmds);

int		export_loop(t_list *tmp);
int		ft_check_varname(char *s);
char	*search_cdpath(char *dir);

#endif

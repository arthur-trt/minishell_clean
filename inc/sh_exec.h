/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:18:59 by atrouill          #+#    #+#             */
/*   Updated: 2021/05/25 13:55:49 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_EXEC_H
# define SH_EXEC_H

# include "minishell.h"

# include <dirent.h>

char	*search_path(char *exec_name);
int		is_builtin(t_list *cmds);
char	**argv_exec_creator(t_list *cmds);
char	**env_exec_creator(void);
int			exec_path(t_list *cmds);

#endif

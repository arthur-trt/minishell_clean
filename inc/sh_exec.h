/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:18:59 by atrouill          #+#    #+#             */
/*   Updated: 2021/05/26 10:16:52 by atrouill         ###   ########.fr       */
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
int		exec_path(t_list *cmds);

int		ft_redirection_check(t_list *cmds, int *fdin, int *fdout);
int		ft_reverse();
int		ft_less(t_list *tmp, int *i, int *fdin);
char	*get_file_name(char *s, int *i);
int			ft_exec(t_lexer *lexed);

#endif

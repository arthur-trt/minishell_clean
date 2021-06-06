/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:18:59 by atrouill          #+#    #+#             */
/*   Updated: 2021/06/05 16:02:42 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_EXEC_H
# define SH_EXEC_H

# include "minishell.h"

# include <dirent.h>

char	*search_path(char *exec_name);
int		is_builtin(t_list *cmds);
int		is_builtin_no_forks(t_list *cmds);
char	**argv_exec_creator(t_list *cmds);
char	**env_exec_creator(void);
int		exec_path(t_list *cmds);

int		ft_redirection_check(t_list *cmds, int *fdin, int *fdout);
int		ft_reverse();
int		ft_less(t_list *tmp, int *i, int *fdin);
int		ft_more(t_list *tmp, int *i, int *fdout);
int		ft_append(t_list *tmp, int *i, int *fdout);
char	*get_file_name(char *s, int *i);
int		ft_exec(t_lexer *lexed);
int		ft_ischarset(char c, char *charset);
t_list	*copycmds(t_list *lst);
int		word_checker(t_list *tmp, char **s);
int		word_checker_bis(t_list *tmp, char **s);
#endif

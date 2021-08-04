/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:18:59 by atrouill          #+#    #+#             */
/*   Updated: 2021/08/04 13:59:54 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_EXEC_H
# define SH_EXEC_H

# include "minishell.h"

# include <dirent.h>

typedef struct s_exec
{
	t_list	*cmds;
	t_lexer	*tmp;
	int		fdin;
	int		fdout;
	int		fdtemp;
	int		fdpipe[2];
	int		status;

}	t_exec;

char	*search_path(char *exec_name);
int		is_builtin(t_list *cmds);
int		is_builtin_no_forks(t_list *cmds);
char	**argv_exec_creator(t_list *cmds);
char	**env_exec_creator(void);
int		exec_path(t_list *cmds);

int		fd_opener(t_list *cmds, int *fdin, int *fdout);
int		ft_reverse(void);
int		ft_less(t_list *tmp, int *i, int *fdin);
int		ft_more(t_list *tmp, int *i, int *fdout);
int		ft_append(t_list *tmp, int *i, int *fdout);
char	*get_file_name(char *s, int *i);
int		ft_exec(t_lexer *lexed);
int		ft_ischarset(char c, char *charset);
t_list	*copycmds(t_list *lst);
int		word_checker(t_list *tmp, char **s);
int		word_checker_bis(t_list *tmp, char **s);
int		heredocs(t_list *cmds);

#endif

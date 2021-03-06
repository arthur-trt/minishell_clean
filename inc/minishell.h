/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:11:42 by atrouill          #+#    #+#             */
/*   Updated: 2021/11/30 13:44:30 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libftprintf/includes/libftprintf.h"

# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <curses.h>
# include <errno.h>
# include <string.h>
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/types.h>

# include "sh_utils.h"
# include "sh_lexer.h"
# include "sh_constants.h"
# include "sh_parser.h"
# include "sh_builtins.h"
# include "sh_input.h"
# include "sh_env.h"
# include "sh_exec.h"

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_glob
{
	t_env					*env;
	volatile sig_atomic_t	ret;
	int						save_out;
	int						save_in;
	int						prog;
	volatile pid_t			pid;
	volatile pid_t			tmp_pid;
	int						d;
	volatile int			c;
	bool					heredocs;
	int						tmp_fdout;
	char					*path;
	bool					d_quote;
	bool					esc;
	bool					expanded;
	int						childs;
}							t_glob;

void	printf_list(t_list *lst);
char	*env_concat(t_env *tmp);

#endif

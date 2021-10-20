/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_input.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 19:57:00 by atrouill          #+#    #+#             */
/*   Updated: 2021/10/20 11:12:24 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_INPUT_H
# define SH_INPUT_H

# include "minishell.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# define MAX_CMD_LINE	4096

# define GREEN					"\001\033[1;32m\002"
# define BLUE					"\001\033[1;94m\002"
# define NEUTRAL				"\001\033[0m\002"

# define KEY_CODE_UP			"\x1b\x5b\x41\0"
# define KEY_CODE_DOWN			"\x1b\x5b\x42\0"
# define KEY_CODE_RIGHT			"\x1b\x5b\x43\0"
# define KEY_CODE_LEFT			"\x1b\x5b\x44\0"
# define KEY_CODE_DEL			"\x1b\x5b\x33\x7e"
# define KEY_CODE_HOME			"\x1b\x5b\x48\0"
# define KEY_CODE_END			"\x1b\x5b\x46\0"
# define KEY_CODE_EOF			"\x04\x00\x00\x00"
# define KEY_CODE_CTRL_LEFT		"\x1b\x5b\x31\x3b\x35\x44"
# define KEY_CODE_CTRL_RIGHT	"\x1b\x5b\x31\x3b\x35\x43"
# define KEY_CODE_CTRL_UP		"\x1b\x5b\x31\x3b\x35\x41"
# define KEY_CODE_CTRL_DOWN		"\x1b\x5b\x31\x3b\x35\x42"
# define KEY_CODE_EXIT_TEST		"\x1b\xff\xff\0"

# define KEY_CTRL_LEFT			1000
# define KEY_CTRL_RIGHT			1001
# define KEY_CTRL_UP			1002
# define KEY_CTRL_DOWN			1003
# define KEY_EOF				1004
# define KEY_CTRL_C				1005

# define HISTORY_PATH			"~/.sh_history"

/*
**
** INPUT FUNCTIONS
**
*/
char	*input(void);
char	*ft_prompt(void);
char	*input_heredocs(t_list **cmds);
bool	replace_var_expand(char *user_input, char **res, size_t *i);

void	history_append(char *cmd);
void	load_history(void);
char	*find_delimiter(t_list *cmds);
void	clean_cmds_heredocs(t_list **cmds);

#endif

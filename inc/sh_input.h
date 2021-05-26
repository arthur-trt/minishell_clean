/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_input.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 19:57:00 by atrouill          #+#    #+#             */
/*   Updated: 2021/05/26 09:53:15 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_INPUT_H
# define SH_INPUT_H

# include "minishell.h"

# define MAX_CMD_LINE	4096

# define KEY_CODE_UP			"\x1b\x5b\x41\0"
# define KEY_CODE_DOWN			"\x1b\x5b\x42\0"
# define KEY_CODE_RIGHT			"\x1b\x5b\x43\0"
# define KEY_CODE_LEFT			"\x1b\x5b\x44\0"
# define KEY_CODE_DEL			"\x1b\x5b\x33\x7e"
# define KEY_CODE_HOME			"\x1b\x5b\x48\0"
# define KEY_CODE_END			"\x1b\x5b\x46\0"
# define KEY_CODE_CTRL_LEFT		"\x1b\x5b\x31\x3b\x35\x44"
# define KEY_CODE_CTRL_RIGHT	"\x1b\x5b\x31\x3b\x35\x43"
# define KEY_CODE_CTRL_UP		"\x1b\x5b\x31\x3b\x35\x41"
# define KEY_CODE_CTRL_DOWN		"\x1b\x5b\x31\x3b\x35\x42"

# define KEY_CTRL_LEFT			1000
# define KEY_CTRL_RIGHT			1001
# define KEY_CTRL_UP			1002
# define KEY_CTRL_DOWN			1003

# define HISTORY_PATH			"./.sh_history"

typedef struct s_hist
{
	char			*line;
	size_t			len;
	struct s_hist	*next;
	struct s_hist	*prev;
}				t_hist;

typedef struct s_size
{
	size_t	row;
	size_t	col;
}	t_size;

typedef struct s_line
{
	char	line[MAX_CMD_LINE];
	size_t	lenght;
	size_t	cursor;
	t_size	cursor_pos;
	t_size	win_size;
	size_t	hist_pos;
}	t_line;

/*
**
** INPUT FUNCTIONS
**
*/
void	set_term_default_mode(void);
void	set_term_raw_mode(void);
t_size	get_win_size(void);
int		get_key(void);
t_size	get_current_cursor_position(void);
bool	insert_char(t_line *input, int c);
bool	delete_char(t_line *input);
bool	delete_char_after(t_line *input);
int		outfun(int c);
int		outfun_str(char *s);
char	*input(t_hist **history);
void	move_cursor_left(t_line *input);
void	move_cursor_right(t_line *input);
void	move_cursor_to_start(t_line *input);
void	move_cursor_to_end(t_line *input);
void	move_cursor_left_word(t_line *input);
void	move_cursor_right_word(t_line *input);
void	move_cursor_prev_line(t_line *input);
void	move_cursor_next_line(t_line *input);
void	set_cursor_pos(t_line input);
void	ft_prompt(void);

/*
**
** HISTORY FUNCTIONS
**
*/
void	history_add_elem_list(t_hist **list, t_hist *new);
t_hist	*history_new_elem_list(char *line, size_t len);
void	append_history(char *input, t_hist **head);
void	print_hist(t_hist *head);
void	free_history(t_hist **head);
void	history_nav_up(t_line *input, t_hist **hist);
void	history_nav_down(t_line *input, t_hist **hist);
t_hist	*construct_hist(void);
bool	backup_history(t_hist *hist);

#endif

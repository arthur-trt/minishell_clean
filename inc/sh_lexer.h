/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:58:54 by atrouill          #+#    #+#             */
/*   Updated: 2021/08/27 15:14:38 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_LEXER_H
# define SH_LEXER_H

typedef enum e_token
{
	T_NO = 0,
	T_PIPE,
	T_SEMICOLON
}				t_token;

typedef struct s_lexer
{
	char			*cmd;
	int				token;
	struct s_lexer	*next;
}					t_lexer;

void	add_cmd_to_lexer(t_lexer **lexer, char *in, t_token token);
t_lexer	*lexer(char *input);
void	print_lexer(t_lexer *lexer);
int		continue_while_quote(char *str, int pos);
t_token	find_previous_token(char *str, int last_pos);
void	free_lexer(t_lexer **lexer);
char	*clean_cmd(char *input);
bool	check_error(char *user_input);

#endif

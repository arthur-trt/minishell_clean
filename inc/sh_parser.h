/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:58:32 by jcueille          #+#    #+#             */
/*   Updated: 2021/10/14 12:46:52 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_PARSER_H
# define SH_PARSER_H
# include "minishell.h"

t_list	*ft_parse(char *s);
char	*ft_double(char *s, int *i, int *r);
int		ft_apply_double(char *s, int *i,
			char *(*f)(char *s, int *i, int *r), char **res);
char	*ft_apply(char *s, int *i, char *(*f)(char *s, int *i), char *res);
char	*ft_apply_var(char *s, int *i, char *res, int *r);
char	*ft_apply_str(char *s, int *i, char *res);
char	*ft_concat(t_list *list, int len);
char	*ft_alloc_concat(t_list *list, int len);
int		ft_quoted_esc(char *s, int *i, t_list **list, int *len);
int		ft_dollar(char *s, int *i, t_list **list, int *len);
int		ft_quoted_str(char *s, int *i, t_list **list, int *len);
char	*ft_search_var(char *s, int *i, int f);
char	*ft_string(char *s, int *i);
char	*ft_single(char *s, int *i);
int		ft_parse_error(t_list *command);
int		ft_double_error(int r, t_list *command, char *res);
void	ft_listclear(t_list **lst);
char	*ft_search_value(char *name, int f);
char	*home_tild(char *res);
int		ft_command_not_found(t_list *command);
int		ft_check_char(t_list *command, char **res, char *s, int *i);
int		double_checker(char *s, int *i, char **res, t_list *command);

int		ft_check_char(t_list *command, char **res, char *s, int *i);
void	ft_check_parser(t_list **cmd);

char	*expand_var(char *user_input);
void	add_char(char **res, char c);

bool	valid_heredocs(char	*user_input);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:58:32 by jcueille          #+#    #+#             */
/*   Updated: 2021/09/06 17:47:38 by jcueille         ###   ########.fr       */
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
int		double_checker(char *s, int *i, char **res, t_list *command);

#endif

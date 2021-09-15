/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:29:21 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/15 08:56:35 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_UTILS_H
# define SH_UTILS_H

# include "minishell.h"

char	*ft_clean_str(char *str);
char	*ft_str_malloc(size_t size);
char	*ft_clean_str(char *str);

void	free_split(char **array);
int		free_list(t_list *lst);

char	*clean_path(char *path);

void	quit_handler(void);
void	int_handler(void);
void	winch_handler(void);
void	sig_handler(int sigld);

bool	can_exec(char *path);
bool	is_dir(char *path);

bool	ft_strisdigit(char *s);

void	ft_putstrerror(char *name, char *error_msg);

char	**ft_split_sh(char *s, char c);

void	skip_quotes(char *s, char c, size_t *i);

#endif

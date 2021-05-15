/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:11:48 by atrouill          #+#    #+#             */
/*   Updated: 2021/05/15 16:54:30 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_BONUS_H
# define SH_BONUS_H

# include <curses.h>
# include <term.h>

# include "minishell.h"

void	special_bonus_keys(t_line *input, int key_code);

#endif

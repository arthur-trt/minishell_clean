/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:18:59 by atrouill          #+#    #+#             */
/*   Updated: 2021/05/24 13:27:28 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_EXEC_H
# define SH_EXEC_H

# include "minishell.h"

# include <dirent.h>

char	*search_path(char *exec_name);

#endif

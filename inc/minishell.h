/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:11:42 by atrouill          #+#    #+#             */
/*   Updated: 2021/05/24 19:00:48 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libftprintf/includes/libftprintf.h"

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
#include <sys/wait.h>


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
	t_env			*env;
	int				ret;
	int				save_out;
	int				save_in;
}					t_glob;

#endif

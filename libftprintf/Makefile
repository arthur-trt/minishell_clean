# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/09 12:00:57 by atrouill          #+#    #+#              #
#    Updated: 2020/06/11 16:02:56 by atrouill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================
#            CONFIG VAR
# ================================

NAME			= libftprintf.a
CC				= gcc

# Compiler flags
CFLAGS			+= -Wall -Werror -Wextra
CPPFLAGS		+= -Iincludes/
MAKEFLAGS		+= --no-print-directory

# Deps
DEPS			= includes/libftprintf.h Makefile

# Source files
SRCS_PATH		= srcs/
SRCS			= \
				ft_atoi       	ft_putnbr_fd	\
				ft_bzero      	ft_putstr_fd	\
				ft_calloc     	ft_split		\
				ft_isalnum    	ft_strchr		\
				ft_isalpha    	ft_strdup		\
				ft_isascii    	ft_strjoin		\
				ft_isdigit    	ft_strlcat		\
				ft_isprint    	ft_strlcpy		\
				ft_itoa       	ft_strlen		\
				ft_memccpy    	ft_strmapi		\
				ft_memchr     	ft_strncmp		\
				ft_memcmp     	ft_strnstr		\
				ft_memcpy     	ft_strrchr		\
				ft_memmove    	ft_strtrim		\
				ft_memset    	ft_substr		\
				ft_putchar_fd 	ft_tolower		\
				ft_putendl_fd 	ft_toupper		\
				ft_strrev		ft_strjoin_free \
				ft_realloc		ft_memdel		\
				ft_strjoin_gnl	get_next_line	\
				buffer				\
				conv_c				\
				conv_d				\
				conv_p				\
				conv_percent			\
				conv_s				\
				conv_u				\
				conv_x				\
				ft_printf				\
				parser				\
				treat_conv			\
				treat_flags			\
				treat_precision		\
				utils

SRCS_BONUS		= $(SRCS) \
				ft_lstadd_back_bonus			\
				ft_lstadd_front_bonus			\
				ft_lstclear_bonus				\
				ft_lstdelone_bonus				\
				ft_lstiter_bonus				\
				ft_lstlast_bonus				\
				ft_lstmap_bonus					\
				ft_lstnew_bonus					\
				ft_lstsize_bonus

# Objects files
OBJS_PATH		= objs/
OBJS_NAME		= $(addsuffix .o, $(SRCS))
OBJS			= $(addprefix $(OBJS_PATH), $(OBJS_NAME))
# OBJS_BONUS_PATH	= objs/
OBJS_BONUS_NAME	= $(addsuffix .o, $(SRCS_BONUS))
OBJS_BONUS		= $(addprefix $(OBJS_PATH), $(OBJS_BONUS_NAME))

# Colors
C_RESET			= \033[0m
C_PENDING		= \033[0;36m
C_SUCCESS		= \033[0;32m

# Escape sequences (ANSI/VT100)
ES_ERASE		= "\033[1A\033[2K\033[1A"
ERASE			= $(ECHO) $(ES_ERASE)

# hide STD/ERR and prevent Make from returning non-zero code
HIDE_STD		= > /dev/null
HIDE_ERR		= 2> /dev/null || true

# Multi platforms
ECHO			= echo
ifeq ($(shell uname),Linux)
	ECHO		+= -e
endif
GREP        	= grep --color=auto --exclude-dir={.bzr,CVS,.git,.hg,.svn}
NORMINETTE		= norminette `ls | grep -v "_main*" | grep -v "test*"`

# ================================
#          MAKE RULES
# ================================

all:				$(NAME)

$(NAME):			$(OBJS)
					@ar rcs $(NAME) $(OBJS) $(HIDE_STD)
					@ranlib $(NAME)
					@$(ECHO) "$(NAME)\t\t[$(C_SUCCESS)✅ $(C_RESET)]"
					@$(ECHO) "$(C_SUCCESS)All done, compilation successful! 👌 $(C_RESET)"

bonus:				$(OBJS_BONUS)
					@ar rcs $(NAME) $(OBJS_BONUS) $(HIDE_STD)
					@ranlib $(NAME)
					@$(ECHO) "$(NAME)\t\t[$(C_SUCCESS)✅ $(C_RESET)]"
					@$(ECHO) "$(C_SUCCESS)All done, compilation successful with bonus! 👌 $(C_RESET)"

$(OBJS_PATH)%.o:	$(SRCS_PATH)%.c $(DEPS)
					@mkdir $(OBJS_PATH) $(HIDE_ERR)
					@$(ECHO) "$(NAME)\t\t[$(C_PENDING)⏳ $(C_RESET)]"
					$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
					@$(ERASE)
					@$(ERASE)

clean:
					@$(RM) -r $(OBJS_PATH) $(HIDE_ERR)
					@$(RM) -r $(NAME).dSYM $(HIDE_ERR)

fclean:				clean
					@$(RM) $(NAME)

re:					fclean all

norm:
					@$(NORMINETTE) | $(GREP) -v "Not a valid file" | $(GREP) "Error\|Warning" -B 1 || true

.PHONY:				clean fclean re all norm

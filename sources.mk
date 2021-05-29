## SOURCES.MK ##

## SRCS ##

SOURCES		+=                                   		\
		srcs/main.c                                 	\


## SRCS/BUILTINS ##

SOURCES		+=                                   		\
		srcs/builtins/ft_cd.c                       	\
		srcs/builtins/ft_echo.c                     	\
		srcs/builtins/ft_env.c                      	\
		srcs/builtins/ft_export.c                   	\
		srcs/builtins/ft_pwd.c                      	\
		srcs/builtins/ft_unset.c                    	\


## SRCS/ENV ##

SOURCES		+=                                   		\
		srcs/env/free.c                             	\
		srcs/env/init.c                             	\
		srcs/env/modify_value.c                     	\
		srcs/env/print_env.c                        	\
		srcs/env/search_key.c                       	\
		srcs/env/split_env.c                        	\


## SRCS/EXEC ##

SOURCES		+=                                   		\
		srcs/exec/exec.c                            	\
		srcs/exec/exec_utils.c                      	\
		srcs/exec/redirections.c                    	\
		srcs/exec/redirections_utils.c              	\
		srcs/exec/search_path.c                     	\


## SRCS/INPUT ##

SOURCES		+=                                   		\
		srcs/input/char.c                           	\
		srcs/input/cursor_pos.c                     	\
		srcs/input/get_key.c                        	\
		srcs/input/get_win_size.c                   	\
		srcs/input/input.c                          	\
		srcs/input/move_cursor.c                    	\
		srcs/input/move_cursor_lines_bonus.c        	\
		srcs/input/move_cursor_words_bonus.c        	\
		srcs/input/outfun.c                         	\
		srcs/input/prompt.c                         	\
		srcs/input/set_term_mode.c                  	\
		srcs/input/special_key_bonus.c              	\


## SRCS/INPUT/HISTORY ##

SOURCES		+=                                   		\
		srcs/input/history/add_elem_history.c       	\
		srcs/input/history/append_history.c         	\
		srcs/input/history/backup_history.c         	\
		srcs/input/history/construct_history.c      	\
		srcs/input/history/free_history.c           	\
		srcs/input/history/history_path.c           	\
		srcs/input/history/nav_history.c            	\
		srcs/input/history/print_history.c          	\


## SRCS/PARSER ##

SOURCES		+=                                   		\
		srcs/parser/apply.c                         	\
		srcs/parser/double.c                        	\
		srcs/parser/dquoted.c                       	\
		srcs/parser/errors.c                        	\
		srcs/parser/parser.c                        	\
		srcs/parser/squoted.c                       	\
		srcs/parser/string.c                        	\
		srcs/parser/utils.c                         	\
		srcs/parser/var.c                           	\


## SRCS/PARSER/LEXER ##

SOURCES		+=                                   		\
		srcs/parser/lexer/add_cmd_to_lexer.c        	\
		srcs/parser/lexer/clean_cmd.c               	\
		srcs/parser/lexer/free_lexer.c              	\
		srcs/parser/lexer/lexer.c                   	\
		srcs/parser/lexer/print_lexer.c             	\


## SRCS/UTILS ##

SOURCES		+=                                   		\
		srcs/utils/free_split.c                     	\
		srcs/utils/ft_clean_str.c                   	\
		srcs/utils/ft_str_malloc.c                  	\


## BONUS ##

SOURCES_BONUS	+= $(SOURCES)                   			\
		srcs/input/move_cursor_lines_bonus.c        	\
		srcs/input/move_cursor_words_bonus.c        	\
		srcs/input/special_key_bonus.c              	\



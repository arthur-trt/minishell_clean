## SOURCES.MK ##

## SRCS ##

SOURCES		+=                                 		\
		srcs/main.c                               	\
		srcs/signals.c                            	\


## SRCS/BUILTINS ##

SOURCES		+=                                 		\
		srcs/builtins/echo.c                      	\
		srcs/builtins/env.c                       	\
		srcs/builtins/export.c                    	\
		srcs/builtins/pwd.c                       	\
		srcs/builtins/unset.c                     	\


## SRCS/ENV ##

SOURCES		+=                                 		\
		srcs/env/free.c                           	\
		srcs/env/init.c                           	\
		srcs/env/modify_value.c                   	\
		srcs/env/search_key.c                     	\


## SRCS/EXEC ##

SOURCES		+=                                 		\
		srcs/exec/exec_utils.c                    	\


## SRCS/INPUT ##

SOURCES		+=                                 		\
		srcs/input/input.c                        	\


## SRCS/PARSER ##

SOURCES		+=                                 		\
		srcs/parser/apply.c                       	\
		srcs/parser/double.c                      	\
		srcs/parser/dquoted.c                     	\
		srcs/parser/errors.c                      	\
		srcs/parser/parser.c                      	\
		srcs/parser/squoted.c                     	\
		srcs/parser/string.c                      	\
		srcs/parser/utils.c                       	\
		srcs/parser/var.c                         	\


## SRCS/PARSER/LEXER ##

SOURCES		+=                                 		\
		srcs/parser/lexer/add_cmd_to_lexer.c      	\
		srcs/parser/lexer/clean_cmd.c             	\
		srcs/parser/lexer/free_lexer.c            	\
		srcs/parser/lexer/lexer.c                 	\
		srcs/parser/lexer/print_lexer.c           	\


## SRCS/UTILS ##

SOURCES		+=                                 		\
		srcs/utils/clean_str.c                    	\
		srcs/utils/dir.c                          	\
		srcs/utils/ft_malloc.c                    	\
		srcs/utils/prompt.c                       	\



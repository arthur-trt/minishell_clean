## SOURCES.MK ##

## SRCS ##

SOURCES		+=                           		\
		srcs/debug.c                        	\
		srcs/main.c                         	\


## SRCS/BUILTINS ##

SOURCES		+=                           		\
		srcs/builtins/export_utils.c        	\
		srcs/builtins/ft_cd.c               	\
		srcs/builtins/ft_cd_cdpath.c        	\
		srcs/builtins/ft_echo.c             	\
		srcs/builtins/ft_env.c              	\
		srcs/builtins/ft_exit.c             	\
		srcs/builtins/ft_export.c           	\
		srcs/builtins/ft_pwd.c              	\
		srcs/builtins/ft_unset.c            	\


## SRCS/ENV ##

SOURCES		+=                           		\
		srcs/env/free.c                     	\
		srcs/env/init.c                     	\
		srcs/env/modify_value.c             	\
		srcs/env/print_env.c                	\
		srcs/env/search_key.c               	\
		srcs/env/split_env.c                	\


## SRCS/EXEC ##

SOURCES		+=                           		\
		srcs/exec/copycmds.c                	\
		srcs/exec/exec.c                    	\
		srcs/exec/exec_command.c            	\
		srcs/exec/exec_utils.c              	\
		srcs/exec/exec_utils2.c             	\
		srcs/exec/heredocs.c                	\
		srcs/exec/init_exec.c               	\
		srcs/exec/pipe.c                    	\
		srcs/exec/redirections.c            	\
		srcs/exec/redirections_utils.c      	\
		srcs/exec/search_path.c             	\


## SRCS/INPUT ##

SOURCES		+=                           		\
		srcs/input/history.c                	\
		srcs/input/input.c                  	\
		srcs/input/promtp.c                 	\


## SRCS/PARSER ##

SOURCES		+=                           		\
		srcs/parser/apply.c                 	\
		srcs/parser/check_char.c            	\
		srcs/parser/check_error.c           	\
		srcs/parser/double.c                	\
		srcs/parser/dquoted.c               	\
		srcs/parser/errors.c                	\
		srcs/parser/expand.c                	\
		srcs/parser/home_tild.c             	\
		srcs/parser/parser.c                	\
		srcs/parser/squoted.c               	\
		srcs/parser/string.c                	\
		srcs/parser/utils.c                 	\
		srcs/parser/var.c                   	\
		srcs/parser/verify.c                	\


## SRCS/UTILS ##

SOURCES		+=                           		\
		srcs/utils/add_char.c               	\
		srcs/utils/clean_path.c             	\
		srcs/utils/file_mode.c              	\
		srcs/utils/free_list.c              	\
		srcs/utils/free_split.c             	\
		srcs/utils/ft_clean_str.c           	\
		srcs/utils/ft_putstrerror.c         	\
		srcs/utils/ft_split_sh.c            	\
		srcs/utils/ft_str_malloc.c          	\
		srcs/utils/ft_strisdigit.c          	\
		srcs/utils/quote_in_var.c           	\
		srcs/utils/signals.c                	\
		srcs/utils/skip_quotes.c            	\



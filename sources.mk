## SOURCES.MK ##

## SRCS ##

SOURCES		+=                             		\
		srcs/main.c                           	\


## SRCS/PARSER ##

SOURCES		+=                             		\
		srcs/parser/check_char.c              	\
		srcs/parser/dquoted.c                 	\
		srcs/parser/check_error_help.c        	\
		srcs/parser/errors.c                  	\
		srcs/parser/string.c                  	\
		srcs/parser/expand.c                  	\
		srcs/parser/expand2.c                 	\
		srcs/parser/parser.c                  	\
		srcs/parser/var.c                     	\
		srcs/parser/home_tild.c               	\
		srcs/parser/verify.c                  	\
		srcs/parser/utils.c                   	\
		srcs/parser/double.c                  	\
		srcs/parser/apply.c                   	\
		srcs/parser/check_error.c             	\
		srcs/parser/squoted.c                 	\


## SRCS/ENV ##

SOURCES		+=                             		\
		srcs/env/modify_value.c               	\
		srcs/env/search_key.c                 	\
		srcs/env/split_env.c                  	\
		srcs/env/free.c                       	\
		srcs/env/print_env.c                  	\
		srcs/env/init.c                       	\


## SRCS/INPUT ##

SOURCES		+=                             		\
		srcs/input/input.c                    	\
		srcs/input/promtp.c                   	\
		srcs/input/heredocs.c                 	\
		srcs/input/command_cleaner.c          	\


## SRCS/BUILTINS ##

SOURCES		+=                             		\
		srcs/builtins/ft_echo.c               	\
		srcs/builtins/ft_cd_cdpath.c          	\
		srcs/builtins/ft_unset.c              	\
		srcs/builtins/ft_exit.c               	\
		srcs/builtins/ft_pwd.c                	\
		srcs/builtins/ft_cd.c                 	\
		srcs/builtins/ft_export.c             	\
		srcs/builtins/check_var.c             	\
		srcs/builtins/ft_env.c                	\


## SRCS/UTILS ##

SOURCES		+=                             		\
		srcs/utils/ft_strisdigit.c            	\
		srcs/utils/ft_strcontain.c            	\
		srcs/utils/free_list.c                	\
		srcs/utils/signals.c                  	\
		srcs/utils/quote_in_var.c             	\
		srcs/utils/file_mode.c                	\
		srcs/utils/ft_putstrerrorparam.c      	\
		srcs/utils/ft_putstrerror.c           	\
		srcs/utils/ft_clean_str.c             	\
		srcs/utils/ft_str_malloc.c            	\
		srcs/utils/clean_path.c               	\
		srcs/utils/add_char.c                 	\
		srcs/utils/free_split.c               	\
		srcs/utils/debug.c                    	\
		srcs/utils/skip_quotes.c              	\
		srcs/utils/ft_split_sh.c              	\


## SRCS/EXEC ##

SOURCES		+=                             		\
		srcs/exec/heredocs.c                  	\
		srcs/exec/init_exec.c                 	\
		srcs/exec/redirections.c              	\
		srcs/exec/exec.c                      	\
		srcs/exec/copycmds.c                  	\
		srcs/exec/exec_utils.c                	\
		srcs/exec/search_path.c               	\
		srcs/exec/exec_command.c              	\
		srcs/exec/exec_utils2.c               	\
		srcs/exec/redirections_utils.c        	\
		srcs/exec/pipe.c                      	\



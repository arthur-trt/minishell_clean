## SOURCES.MK ##

## SRCS ##

SOURCES		+=                           		\
		srcs/debug.c                        	\
		srcs/main.c                         	\


## SRCS/UTILS ##

SOURCES		+=                           		\
		srcs/utils/signals.c                	\
		srcs/utils/free_list.c              	\
		srcs/utils/ft_str_malloc.c          	\
		srcs/utils/ft_clean_str.c           	\
		srcs/utils/clean_path.c             	\
		srcs/utils/ft_strisdigit.c          	\
		srcs/utils/free_split.c             	\
		srcs/utils/file_mode.c              	\
		srcs/utils/ft_putstrerror.c         	\


## SRCS/INPUT ##

SOURCES		+=                           		\
		srcs/input/input.c                  	\
		srcs/input/promtp.c                 	\
		srcs/input/history.c                	\


## SRCS/PARSER ##

SOURCES		+=                           		\
		srcs/parser/parser.c                	\
		srcs/parser/home_tild.c             	\
		srcs/parser/string.c                	\
		srcs/parser/check_error.c           	\
		srcs/parser/dquoted.c               	\
		srcs/parser/errors.c                	\
		srcs/parser/apply.c                 	\
		srcs/parser/double.c                	\
		srcs/parser/var.c                   	\
		srcs/parser/squoted.c               	\
		srcs/parser/utils.c                 	\


## SRCS/ENV ##

SOURCES		+=                           		\
		srcs/env/split_env.c                	\
		srcs/env/init.c                     	\
		srcs/env/free.c                     	\
		srcs/env/print_env.c                	\
		srcs/env/modify_value.c             	\
		srcs/env/search_key.c               	\


## SRCS/EXEC ##

SOURCES		+=                           		\
		srcs/exec/exec.c                    	\
		srcs/exec/pipe.c                    	\
		srcs/exec/copycmds.c                	\
		srcs/exec/exec_utils.c              	\
		srcs/exec/heredocs.c                	\
		srcs/exec/init_exec.c               	\
		srcs/exec/redirections_utils.c      	\
		srcs/exec/exec_utils2.c             	\
		srcs/exec/search_path.c             	\
		srcs/exec/redirections.c            	\
		srcs/exec/exec_command.c            	\


## SRCS/BUILTINS ##

SOURCES		+=                           		\
		srcs/builtins/ft_env.c              	\
		srcs/builtins/ft_cd_cdpath.c        	\
		srcs/builtins/ft_exit.c             	\
		srcs/builtins/ft_unset.c            	\
		srcs/builtins/ft_echo.c             	\
		srcs/builtins/ft_pwd.c              	\
		srcs/builtins/ft_cd.c               	\
		srcs/builtins/ft_export.c           	\
		srcs/builtins/export_utils.c



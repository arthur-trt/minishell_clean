## SOURCES.MK ##

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
		srcs/input/set_term_mode.c                  	\
		srcs/input/special_key_bonus.c              	\


## SRCS/INPUT/HISTORY ##

SOURCES		+=                                   		\
		srcs/input/history/add_elem_history.c       	\
		srcs/input/history/append_history.c         	\
		srcs/input/history/backup_history.c         	\
		srcs/input/history/construct_history.c      	\
		srcs/input/history/free_history.c           	\
		srcs/input/history/nav_history.c            	\
		srcs/input/history/print_history.c          	\


## BONUS ##

SOURCES_BONUS	+= $(SOURCES)                   			\
		srcs/input/move_cursor_lines_bonus.c        	\
		srcs/input/move_cursor_words_bonus.c        	\
		srcs/input/special_key_bonus.c              	\



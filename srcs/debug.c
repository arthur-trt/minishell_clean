#include "../inc/minishell.h"

void	printf_list(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		printf("cmds: %s\n", tmp->content);
		tmp = tmp->next;
	}
}

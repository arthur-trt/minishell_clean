#include "inc/minishell.h"

int main()
{
	t_list *test;

	test = malloc(sizeof(t_list*));
	test->content = ft_strdup("beyonce");
	int i = -1;
	while (*(char*)test->content[++i]))
		printf("%c", (test->content[i]));
	return (0);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minishell.h"

int	main(void)
{
	char	*tmp;

	tmp = readline("> ");
	printf("Ret %d\n", ft_strcmp(tmp, "EOF"));
	free(tmp);
	tmp = NULL;
	if (tmp)
		printf("True\n");
	//free(tmp);
	return (0);
}

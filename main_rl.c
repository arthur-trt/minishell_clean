#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

int	main(void)
{
	char	*line;

	line = readline("PS > ");
	printf("ret : %s\n", line);
	free(line);
	return (0);
}

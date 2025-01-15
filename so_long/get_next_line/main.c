#include <stdio.h>
#include "get_next_line.h"

int main()
{
	char *str;

	while (1)
	{
		str = get_next_line(STDIN_FILENO);
		if (!str)
			break ;
		printf("%s", str);
		free(str);
	}
}
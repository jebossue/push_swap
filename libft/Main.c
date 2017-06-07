#include "get_next_line.h"
#include "stdio.h"

int	main()
{
	char *line;

	while (get_next_line(0, &line) == 1)
		printf("%s\n", line);
	return (0);
}

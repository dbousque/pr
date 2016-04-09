

#include "errors.h"

void	malloc_error(void)
{
	print_chars("Could not allocate memory.\n");
	exit(1);
}
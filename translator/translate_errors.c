

#include "translate_errors.h"

void	file_opening_error(void)
{
	print_chars("Could not open file.\n");
}

void	file_reading_error(void)
{
	print_chars("An error occured while reading file.\n");
}
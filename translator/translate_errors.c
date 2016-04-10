

#include "translate_errors.h"

void	file_opening_error(void)
{
	print_chars("Could not open file.");
}

void	file_opening_for_writing_error(void)
{
	print_chars("Could not open file for writing.");
}

void	file_reading_error(void)
{
	print_chars("An error occured while reading file.");
}
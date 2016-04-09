

#include "translator.h"

void	print_details(void)
{
	print_chars("Please specify a file as input.\n");
}

void	translate_file(char *filename)
{
	t_string		*file_content;
	t_linked_list	*lines;
	int				i;

	file_content = read_file_fast(filename);
	lines = split_string(file_content, '\n');
	i = 0;
	while (i < lines->len)
	{
		print_chars("new line.");
		print((t_string*)lines->elts[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc <= 1)
	{
		print_details();
		return (0);
	}
	translate_file(argv[1]);
	return (0);
}


#include "translator.h"

void	print_details(void)
{
	print_chars("Please specify a file as input.\n");
}

void	interpret_lines(t_string *res_filename, t_linked_list *lines)
{
	(void)res_filename;
	(void)lines;
	print(res_filename);
}

void	translate_file(t_string *filename)
{
	t_string		*file_content;
	t_linked_list	*lines;
	int				i;

	file_content = read_file_fast(filename->chars);
	replace_subpart(filename, filename->len - 3, filename->len, ".c", 2);
	lines = split_string(file_content, '\n');
	i = 0;
	while (i < lines->len)
	{
		print_chars("new line.");
		print((t_string*)lines->elts[i]);
		i++;
	}
	interpret_lines(filename, lines);
}

int		main(int argc, char **argv)
{
	t_string	*filename;

	if (argc <= 1)
	{
		print_details();
		return (0);
	}
	filename = new_string_from_chars(argv[1], ft_strlen(argv[1]));
	translate_file(filename);
	return (0);
}
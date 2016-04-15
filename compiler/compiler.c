

#include "compiler.h"

void	print_details(void)
{
	ft_putstr("Please specify an input file.\n");
}

void	parse_n_compile_file(char *filename)
{
	char			*file_content;
	long			file_len;
	t_linked_list	*splitted_lines;
	t_linked_list	*abstracted_layer;
	t_linked_list	*resolved_layer;

	file_content = read_file_fast(filename, &file_len);
	splitted_lines = parse(file_content, file_len);
	abstracted_layer = make_abstraction_layer(splitted_lines);
	check_indentation(abstracted_layer);
	check_parentheses_and_brackets_close(abstracted_layer);
	resolved_layer = resolve_layer(abstracted_layer, splitted_lines);
	(void)file_content;
	(void)splitted_lines;
	(void)resolved_layer;
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		print_details();
	else
	{
		parse_n_compile_file(argv[1]);
	}
	return (0);
}
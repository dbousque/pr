

#include "compiler.h"

void	print_details(void)
{
	ft_putstr("Please specify an input file.\n");
}

char	*make_res_filename(char *filename)
{
	char	*res_filename;
	int		i;
	int		x;

	i = ft_strlen(filename);
	i--;
	while (i >= 0 && filename[i] != '.')
		i--;
	if (!(res_filename = (char*)malloc(sizeof(char) * (i + 3))))
		malloc_error();
	res_filename[i + 2] = '\0';
	res_filename[i + 1] = 'c';
	x = 0;
	while (x <= i)
	{
		res_filename[x] = filename[x];
		x++;
	}
	return (res_filename);
}

void	write_start_of_file(int fd)
{
	char	*start;

	start = "\n\n#include \"../../language/language.h\"\n\n";
	write(fd, start, ft_strlen(start));
}

void	write_end_of_file(int fd)
{
	char	*end;

	end = "int\t\tmain(int argc, char **argv)\n{\n\tt_variable\t*args;\n\n\targs = _args_from_c_args(argc, argv);\n\t__main(args);\n\treturn (0);\n}";
	write(fd, end, ft_strlen(end));
}

void	write_functions_to_file(int fd, t_linked_list *code_functions)
{
	int		i;

	i = 0;
	while (i < code_functions->len)
	{
		write(fd, ((char*)code_functions->elts[i]), ft_strlen((char*)code_functions->elts[i]));
		write(fd, "\n\n", 2);
		i++;
	}
}

void	write_code_to_res_file(char *filename, t_linked_list *code_functions)
{
	int		fd;

	fd = open(filename, O_RDWR | O_CREAT | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd < 0)
	{
		ft_putstr("Could not open file for writing\n");
		exit(1);
	}
	write_start_of_file(fd);
	write_functions_to_file(fd, code_functions);
	write_end_of_file(fd);
}

void	parse_n_compile_file(char *filename)
{
	char			*file_content;
	long			file_len;
	t_linked_list	*splitted_lines;
	t_linked_list	*abstracted_layer;
	t_linked_list	*resolved_layer;
	t_linked_list	*functions;
	t_linked_list	*code_functions;
	//t_tree			*syntax_tree;
	char			*res_filename;

	file_content = read_file_fast(filename, &file_len);
	splitted_lines = parse(file_content, file_len);
	abstracted_layer = make_abstraction_layer(splitted_lines);
	check_indentation(abstracted_layer);
	check_parentheses_and_brackets_close(abstracted_layer);
	resolved_layer = resolve_layer(abstracted_layer, splitted_lines);
	functions = cut_into_functions(resolved_layer, &splitted_lines);
	code_functions = functions_to_c_code(functions, splitted_lines);
	//syntax_tree = get_tree_from_layer(resolved_layer);
	res_filename = make_res_filename(filename);
	write_code_to_res_file(res_filename, code_functions);
	(void)functions;
	(void)file_content;
	(void)splitted_lines;
	(void)resolved_layer;
	(void)code_functions;
	(void)res_filename;
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
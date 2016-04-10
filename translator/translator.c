

#include "translator.h"

void	print_details(void)
{
	print_chars("Please specify a file as input.");
}

void	compile_output(t_string *filename)
{
	t_string	*to_execute;
	char		*compile_command;

	compile_command = "gcc ../langage/*.c ";
	to_execute = new_string_from_chars(compile_command, ft_strlen(compile_command));
	concat_strings(to_execute, filename);
	system(to_execute->chars);
}

void	interpret_lines(int fd, t_linked_list *lines)
{
	t_linked_list	*current_line_instructions;
	t_linked_list	*current_line_strings;
	int				line_nb;
	int				char_nb;
	t_string		*tmp_line;
	t_string		*tmp_word;
	char			*tmp_char;

	current_line_strings = new_list();
	current_line_instructions = new_list();
	line_nb = 0;
	while (line_nb < lines->len)
	{
		tmp_line = ((t_string*)lines->elts[line_nb]);
		char_nb = 0;
		while (char_nb < tmp_line->len)
		{
			if (!(tmp_char = (char*)malloc(sizeof(char))))
				malloc_error();
			*tmp_char = tmp_line->chars[char_nb];
			while (char_nb < tmp_line->len && char_in_string(*tmp_char, IGNORE, ft_strlen(IGNORE)))
			{
				char_nb++;
				*tmp_char = tmp_line->chars[char_nb];
			}
			
			char_nb++;
		}
		write(fd, "\n", 1);
		line_nb++;
	}
}

int		write_start_and_get_fd(t_string *res_filename)
{
	int		fd;
	char	*to_write;

	fd = open(res_filename->chars, O_RDWR | O_CREAT | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd < 0)
	{
		file_opening_for_writing_error();
		exit(1);
	}
	to_write = "\n\n#include \"langage.h\"\n\nint\t\tmain(int argc, char **argv)\n{\n";
	write(fd, to_write, ft_strlen(to_write));
	return (fd);
}

void	write_end_of_file(int fd)
{
	char	*to_write;

	to_write = "}";
	write(1, to_write, ft_strlen(to_write));
}

void	translate_file(t_string *filename)
{
	t_string		*file_content;
	t_linked_list	*lines;
	int				i;
	int				fd;

	file_content = read_file_fast(filename->chars);
	replace_subpart(filename, filename->len - 3, filename->len, ".c", 2);
	concat_strings(filename, new_string_from_chars("\0", 1));
	lines = split_string(file_content, '\n');
	i = 0;
	while (i < lines->len)
	{
		print_chars("new line.");
		print_string((t_string*)lines->elts[i]);
		i++;
	}
	fd = write_start_and_get_fd(filename);
	interpret_lines(fd, lines);
	write_end_of_file(fd);
	compile_output(filename);
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
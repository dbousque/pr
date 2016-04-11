

#include "translator.h"

void	print_details(void)
{
	print_chars("Please specify a file as input.");
}

void	compile_output(t_string *filename)
{
	t_string	*to_execute;
	char		*compile_command;

	compile_command = "gcc ../language/*.c ../utils/*.c -O3 ";
	to_execute = new_string_from_chars(compile_command, ft_strlen(compile_command));
	concat_strings(to_execute, filename);
	system(to_execute->chars);
}

void	interpret_word(t_linked_list *current_line_instructions, t_linked_list *current_line_strings,
														t_linked_list *known_vars, t_string *tmp_word)
{
	if (string_in_chartab(tmp_word, STR_KEYWORDS, NB_KEYWORDS))
		add_to_list(current_line_instructions, _new_char(KEYWORD));
	else if (equals_chars(tmp_word->chars, STR_EQUALS, tmp_word->len, ft_strlen(STR_EQUALS)))
		add_to_list(current_line_instructions, _new_char(EQUALS));
	else if (equals_chars(tmp_word->chars, STR_EQUALITY_CHECK, tmp_word->len, ft_strlen(STR_EQUALITY_CHECK)))
		add_to_list(current_line_instructions, _new_char(EQUALITY_CHECK));
	else if (equals_chars(tmp_word->chars, STR_CPY_CHAR, tmp_word->len, ft_strlen(STR_CPY_CHAR)))
		add_to_list(current_line_instructions, _new_char(CPY_CHAR));
	else if (char_in_string(tmp_word->chars[0], STR_OPERATION_SYMBOLS, ft_strlen(STR_OPERATION_SYMBOLS)))
		add_to_list(current_line_instructions, _new_char(OPERATION_SYMBOL));
	else if (char_in_string(tmp_word->chars[0], STR_SEPARATOR_SYMBOLS, ft_strlen(STR_SEPARATOR_SYMBOLS)))
		add_to_list(current_line_instructions, _new_char(SEPARATOR_SYMBOL));
	else
	{
		// Can be a function, a variable or a value
		
		// is it a value ?
		if (char_in_string(tmp_word->chars[0], STR_VALUE_START, ft_strlen(STR_VALUE_START)))
			add_to_list(current_line_instructions, _new_char(VALUE));
		else if (string_in_chartab(tmp_word, STR_BUILTIN_FUNCTIONS, NB_BUILTIN_FUNCTIONS))
			add_to_list(current_line_instructions, _new_char(BUILTIN_FUNCTION));
		else
		{
			// Here, it must be a variable, known or new
			if (string_in_linked_list(tmp_word, known_vars))
				add_to_list(current_line_instructions, _new_char(VARIABLE));
			else
			{
				add_to_list(current_line_instructions, _new_char(UNKNOWN));
				add_to_list(known_vars, new_var_from_string(tmp_word));
			}
		}
	}
	add_to_list(current_line_strings, new_var_from_string(tmp_word));
}

void	interpret_lines(int fd, t_linked_list *lines)
{
	t_linked_list	*current_line_instructions;
	t_linked_list	*current_line_strings;
	t_linked_list	*known_vars;
	int				line_nb;
	int				char_nb;
	t_string		*tmp_line;
	t_string		*tmp_word;
	char			tmp_char;

	known_vars = new_list();
	line_nb = 0;
	while (line_nb < lines->len)
	{
		current_line_strings = new_list();
		current_line_instructions = new_list();
		tmp_line = ((t_string*)lines->elts[line_nb]);
		char_nb = 0;
		while (char_nb < tmp_line->len)
		{
			tmp_word = new_string();
			tmp_char = tmp_line->chars[char_nb];
			while (char_nb < tmp_line->len && char_in_string(tmp_char, IGNORE, ft_strlen(IGNORE)))
			{
				char_nb++;
				tmp_char = tmp_line->chars[char_nb];
			}
			while (char_nb < tmp_line->len && !char_in_string(tmp_char, IGNORE, ft_strlen(IGNORE)))
			{
				add_char_to_string(tmp_word, tmp_char);
				char_nb++;
				tmp_char = tmp_line->chars[char_nb];
			}
			interpret_word(current_line_instructions, current_line_strings, known_vars, tmp_word);
			char_nb++;
		}
		instructions_to_code(current_line_instructions, current_line_strings, fd);
		write(fd, "\n", 1);
		line_nb++;
	}
	//print_linked_list_nl(current_line_instructions);
	//print_linked_list_nl(current_line_strings);
	//print_linked_list_nl(known_vars);
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
	to_write = "\n\n#include \"../../language/language.h\"\n\nint\t\tmain(int argc, char **argv)\n{\n";
	write(fd, to_write, ft_strlen(to_write));
	return (fd);
}

void	write_end_of_file(int fd)
{
	char	*to_write;

	to_write = "}";
	write(fd, to_write, ft_strlen(to_write));
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
		//print_chars("new line.");
		print_string_nl((t_string*)lines->elts[i]);
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
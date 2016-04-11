

#include "instructions_to_code.h"

char	match_patterns(t_linked_list *instructions, int start, char pattern[], int pattern_len)
{
	int 	i;

	i = 0;
	if (start + pattern_len > instructions->len)
		return (0);
	while (i < pattern_len)
	{
		if (*((char*)((t_variable*)instructions->elts[start + i])->val) != pattern[i])
			return (0);
		i++;
	}
	return (1);
}

void	instructions_to_code(t_linked_list *current_line_instructions, t_linked_list *current_line_strings, int fd)
{
	print_linked_list_nl(current_line_strings);
	print_linked_list_nl(current_line_instructions);
	(void)fd;
	int			i;
	t_string	*tmp_str;
	t_string	*tmp_string;

	i = 0;
	while (i < current_line_instructions->len)
	{
		tmp_string = ((t_string*)((t_variable*)current_line_strings->elts[i])->val);
		if (match_patterns(current_line_instructions, i, NEW_INSTANTIATION, 2))
		{
			write(fd, "t_variable *", 12);
			write(fd, tmp_string->chars, tmp_string->len);
			write(fd, " = ", 3);
			i += 2;
		}
		else if (match_patterns(current_line_instructions, i, REINSTANTIATION, 2))
		{
			write(fd, tmp_string->chars, tmp_string->len);
			write(fd, " = ", 3);
			i += 2;
		}
		else if (match_patterns(current_line_instructions, i, PRINT, 2))
		{
			tmp_str = ((t_string*)((t_variable*)current_line_strings->elts[i + 1])->val);
			write(fd, "print(", 6);
			write(fd, tmp_str->chars, tmp_str->len);
			write(fd, ");", 2);
			i += 2;
		}
		else if (match_patterns(current_line_instructions, i, PRINT2, 2))
		{
			tmp_str = ((t_string*)((t_variable*)current_line_strings->elts[i + 1])->val);
			if (char_in_string(tmp_str->chars[0], STR_STRING_DELIMIT, ft_strlen(STR_STRING_DELIMIT)))
			{
				// string
				write(fd, "print_chars_of_size(", 20);
				write(fd, tmp_str->chars, tmp_str->len);
				write(fd, ", ", 2);
				write(fd, ft_itoa(tmp_str->len - 2), pos_int_str_len(tmp_str->len - 2));
				write(fd, ");", 2);
			}
			else if (char_in_string(tmp_str->chars[0], STR_NUMBER, ft_strlen(STR_NUMBER)))
			{
				// int
				write(fd, "print_chars_of_size(\"", 21);
				write(fd, tmp_str->chars, tmp_str->len);
				write(fd, "\", ", 3);
				write(fd, ft_itoa(tmp_str->len), pos_int_str_len(tmp_str->len));
				write(fd, ");", 2);
			}
			i += 2;
		}
		else if (match_patterns(current_line_instructions, i, NEW_VALUE, 1))
		{
			// if string
			if (char_in_string(tmp_string->chars[0], STR_STRING_DELIMIT, ft_strlen(STR_STRING_DELIMIT)))
			{
				write(fd, "_new_string_from_chars(", 23);
				write(fd, tmp_string->chars, tmp_string->len);
				write(fd, ", ", 2);
				write(fd, ft_itoa(tmp_string->len - 2), ft_strlen(ft_itoa(tmp_string->len - 2)));
				write(fd, ");", 2);
			}
			else if (char_in_string(tmp_str->chars[0], STR_NUMBER, ft_strlen(STR_NUMBER)))
			{
				// int
				write(fd, "_new_int_from_chars(\"", 21);
				write(fd, tmp_str->chars, tmp_str->len);
				write(fd, "\", ", 3);
				write(fd, ft_itoa(tmp_str->len), pos_int_str_len(tmp_str->len));
				write(fd, ");", 2);
			}
			else
			{
				write(1, "NOT GOOD\n", 9);
			}
			i++;
		}
		else
		{
			write(1, "BIG PROBLEM, pattern not recognized!\n", ft_strlen("BIG PROBLEM, pattern not recognized!\n"));
			exit(1);
		}
	}
}
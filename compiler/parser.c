

#include "parser.h"

int		handle_start_chars(char *line, t_linked_list *res, char car)
{
	int				tmp;
	char			*tmp_str;
	int				i;

	i = 0;
	if (line[0] == car)
	{
		while (line[i] == car)
			i++;
		tmp = 0;
		while (tmp < i)
		{
			if (!(tmp_str = (char*)malloc(sizeof(char) * 2)))
				malloc_error();
			tmp_str[0] = car;
			tmp_str[1] = '\0';
			add_to_list(res, tmp_str);
			tmp++;
		}
	}
	return (i);
}

int		handle_quote(t_linked_list *res, char *line, int i, char quote)
{
	int				tmp;
	int				tmp2;
	char			*tmp_str;

	//ft_putstr("CALLED\n");
	//write(1, &quote, 1);
	if (i > 0 && line[i - 1] == '\\')
	{
		ft_putstr("Invalid sequences of characters outside of a string : \\");
		write(1, &quote, 1);
		ft_putstr("\n");
		exit(1);
	}
	tmp = i;
	//i++ to skip the fist "
	i++;
	while (line[i] && (line[i] != quote || (line[i - 1] == '\\' && (i < 2 || line[i - 2] != '\\'))))
	{
		//ft_putstr("la\n");
		i++;
	}
	// end of line without closing "
	if (!line[i])
	{
		ft_putstr("String or char is not closed.\n");
		exit(1);
	}
	// i++ to take the last "
	i++;
	if (!(tmp_str = (char*)malloc(sizeof(char) * (i - tmp + 1))))
		malloc_error();
	tmp_str[i - tmp] = '\0';
	tmp2 = 0;
	while (tmp < i)
	{
		tmp_str[tmp2] = line[tmp];
		tmp++;
		tmp2++;
	}
	//ft_putstr(tmp_str);
	add_to_list(res, tmp_str);
	return (i);
}

t_linked_list	*parse_line(char *line)
{
	int				i;
	int				tmp;
	int				tmp2;
	t_linked_list	*res;
	char			*tmp_str;

	res = new_list();
	i = 0;
	i = handle_start_chars(line, res, '\t');
	if (i != 0 && line[i] == ' ')
	{
		ft_putstr("Invalid start of line, tabs mixed with spaces.\n");
		exit(1);
	}
	i = handle_start_chars(line, res, ' ');
	while (1)
	{
		tmp = i;
		while (line[i] && !char_in_string(line[i], SPLIT_N_IGNORE) && !char_in_string(line[i], SPLIT_N_KEEP) && (line[i] != POINT_CHAR || is_number(line[i + 1])))
		{
			// special thing for strings and chars with " and '
			if (line[i] == '"')
			{
				i = handle_quote(res, line, i, '"');
				tmp = i;
			}
			else if (line[i] == '\'')
			{
				i = handle_quote(res, line, i, '\'');
				tmp = i;
			}
			else
				i++;
		}
		// there is a word to read
		if (tmp != i)
		{
			if (!(tmp_str = (char*)malloc(sizeof(char) * (i - tmp + 1))))
				malloc_error();
			tmp_str[i - tmp] = '\0';
			tmp2 = 0;
			while (tmp < i)
			{
				tmp_str[tmp2] = line[tmp];
				tmp++;
				tmp2++;
			}
			add_to_list(res, tmp_str);
		}
		// if it wasnt the last character, that means there are \t ;,( ... to split on
		if (line[i])
		{
			if (char_in_string(line[i], SPLIT_N_IGNORE))
			{
				while (line[i] && char_in_string(line[i], SPLIT_N_IGNORE))
					i++;
			}
			else
			{
				//SPLIT_N_KEEP characters
				tmp = i;
				while (line[i] && (char_in_string(line[i], SPLIT_N_KEEP) || line[i] == POINT_CHAR))
				{
					if (!(tmp_str = (char*)malloc(sizeof(char) * 2)))
						malloc_error();
					tmp_str[0] = line[i];
					tmp_str[1] = '\0';
					add_to_list(res, tmp_str);
					i++;
				}
			}
		}
		if (!line[i])
			break ;
	}
	return (res);
}

void	print_splitted_lines(t_linked_list *lines)
{
	int		i;
	int		x;

	i = 0;
	while (i < lines->len)
	{
		x = 0;
		while (x < ((t_linked_list*)lines->elts[i])->len)
		{
			write(1, "\"", 1);
			ft_putstr(((t_linked_list*)lines->elts[i])->elts[x]);
			write(1, "\",   ", 5);
			x++;
		}
		ft_putstr("\n");
		i++;
	}
}

t_linked_list	*parse(char *file_content, long file_len)
{
	char			**lines;
	int				i;
	t_linked_list	*splitted_lines;

	lines = split_on_char(file_content, file_len, '\n');
	splitted_lines = new_list();
	i = 0;
	while (lines[i])
	{
		//ft_putstr(lines[i]);
		//write(1, "\n\n", 2);
		add_to_list(splitted_lines, parse_line(lines[i]));
		i++;
	}
	//print_splitted_lines(splitted_lines);
	return (splitted_lines);
}
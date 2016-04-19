

#include "functions_to_c_code.h"

static int		get_line_indentation_level(t_linked_list *line)
{
	int		i;

	i = 0;
	while (i < line->len && *((char*)line->elts[i]) == INDENT)
		i++;
	return (i);
}

t_linked_list	*get_created_vars_in_function(t_linked_list *func, t_linked_list *func_strings, t_linked_list *args)
{
	t_linked_list	*created_vars;
	int				i;
	int				x;
	t_linked_list	*tmp_line;
	t_linked_list	*tmp_line_strings;

	created_vars = new_list();
	// set to 1 to skip the first line, who contains the function prototype
	i = 1;
	while (i < func->len)
	{
		tmp_line = ((t_linked_list*)func->elts[i]);
		tmp_line_strings = ((t_linked_list*)func_strings->elts[i]);
		x = 0;
		while (x < tmp_line->len)
		{
			if (*((char*)tmp_line->elts[x]) == VAR_NAME && x + 1 < tmp_line->len
					&& *((char*)tmp_line->elts[x + 1]) == EQUAL && !string_in_list(((char*)tmp_line_strings->elts[x]), args))
				add_to_list(created_vars, ((char*)tmp_line_strings->elts[x]));
			x++;
		}
		i++;
	}
	return (created_vars);
}

t_linked_list	*get_args_name(t_linked_list *first_line, t_linked_list *first_line_strings)
{
	int				i;
	t_linked_list	*args;

	args = new_list();
	i = 0;
	while (i < first_line->len)
	{
		if (*((char*)first_line->elts[i]) == VAR_NAME)
			add_to_list(args, ((char*)first_line_strings->elts[i]));
		i++;
	}
	return (args);
}

char	does_function_return(t_linked_list *func, t_linked_list *func_strings)
{
	int				i;
	int				x;
	t_linked_list	*tmp_line;
	t_linked_list	*tmp_line_strings;

	i = 0;
	while (i < func->len)
	{
		tmp_line = ((t_linked_list*)func->elts[i]);
		tmp_line_strings = ((t_linked_list*)func_strings->elts[i]);
		x = 0;
		while (x < tmp_line->len && *((char*)tmp_line->elts[x]) == INDENT)
			x++;
		if (x < tmp_line->len && *((char*)tmp_line->elts[x]) == KEYWORD && ft_strcmp((char*)tmp_line_strings->elts[x], "return") == 0)
			return (1);
		i++;
	}
	return (0);
}

char 	*list_to_string(t_linked_list *list)
{
	int		length;
	int		i;
	int		x;
	int		tmp_len;
	char	*string;

	length = 0;
	i = 0;
	while (i < list->len)
	{
		length += ft_strlen((char*)list->elts[i]);
		i++;
	}
	if (!(string = (char*)malloc(sizeof(char) * (length + 1))))
		malloc_error();
	string[length] = '\0';
	length = 0;
	i = 0;
	while (i < list->len)
	{
		tmp_len = ft_strlen((char*)list->elts[i]);
		x = length;
		while (x < tmp_len + length)
		{
			string[x] = ((char*)list->elts[i])[x - length];
			x++;
		}
		length += tmp_len;
		i++;
	}
	return (string);
}

char 	*list_to_string_with_nl(t_linked_list *list)
{
	int		length;
	int		i;
	int		x;
	int		tmp_len;
	char	*string;

	length = 0;
	i = 0;
	while (i < list->len)
	{
		length += ft_strlen((char*)list->elts[i]) + 1;
		i++;
	}
	if (!(string = (char*)malloc(sizeof(char) * (length + 1))))
		malloc_error();
	string[length] = '\0';
	length = 0;
	i = 0;
	while (i < list->len)
	{
		tmp_len = ft_strlen((char*)list->elts[i]);
		x = length;
		while (x < tmp_len + length)
		{
			string[x] = ((char*)list->elts[i])[x - length];
			x++;
		}
		string[x] = '\n';
		length += tmp_len + 1;
		i++;
	}
	return (string);
}

char	*get_function_prototype(t_linked_list *first_line, t_linked_list *first_line_strings, int indentation, char returns)
{
	int				i;
	t_linked_list	*string;
	char			first_arg;

	first_arg = 1;
	string = new_list();
	i = 0;
	while (i < indentation)
	{
		add_to_list(string, ft_strdup("\t"));
		i++;
	}
	if (returns)
		add_to_list(string, ft_strdup("t_variable\t*__"));
	else
		add_to_list(string, ft_strdup("void\t\t__"));
	while (i < first_line->len)
	{
		if (*((char*)first_line->elts[i]) == FUNCTION_NAME)
		{
			add_to_list(string, ((char*)first_line_strings->elts[i]));
			add_to_list(string, ft_strdup("("));
		}
		else if (*((char*)first_line->elts[i]) == VAR_NAME)
		{
			if (!first_arg)
				add_to_list(string, ft_strdup(", "));
			first_arg = 0;
			add_to_list(string, ft_strdup("t_variable *"));
			add_to_list(string, ((char*)first_line_strings->elts[i]));
		}
		i++;
	}
	add_to_list(string, ft_strdup(")"));
	return (list_to_string(string));
}

char	*declare_created_variables(t_linked_list *vars, int indentation)
{
	t_linked_list	*string;
	int				i;
	int				x;

	string = new_list();
	i = 0;
	while (i < vars->len)
	{
		x = 0;
		while (x < indentation)
		{
			add_to_list(string, ft_strdup("\t"));
			x++;
		}
		add_to_list(string, ft_strdup("t_variable\t*"));
		add_to_list(string, (char*)vars->elts[i]);
		add_to_list(string, ft_strdup(";\n"));
		i++;
	}
	return (list_to_string(string));
}

char	*string_from_char_with_indent(int indentation, char c)
{
	char	*str;
	int		i;

	if (!(str = (char*)malloc(sizeof(char) * (indentation + 2))))
		malloc_error();
	str[indentation + 1] = '\0';
	str[indentation] = c;
	i = 0;
	while (i < indentation)
	{
		str[i] = '\t';
		i++;
	}
	return (str);
}

char	line_is_assignment(t_linked_list *tmp_line)
{
	int		i;

	i = 0;
	while (i < tmp_line->len && *((char*)tmp_line->elts[i]) == INDENT)
		i++;
	if (i + 1 < tmp_line->len && *((char*)tmp_line->elts[i]) == VAR_NAME
								&& *((char*)tmp_line->elts[i + 1]) == EQUAL)
		return (1);
	return (0);
}

void	handle_assignment(t_linked_list *tmp_line, t_linked_list *tmp_line_strings,
													t_linked_list *code, int current_indent)
{
	int				i;
	t_linked_list	*string;

	string = new_list();
	i = 0;
	while (i < current_indent)
	{
		add_to_list(string, ft_strdup("\t"));
		i++;
	}
	i = 0;
	while (i < tmp_line->len && *((char*)tmp_line->elts[i]) == INDENT)
		i++;
	add_to_list(string, (char*)tmp_line_strings->elts[i]);
	add_to_list(string, ft_strdup(" = "));
	i += 2;
	add_to_list(string, resolve_part(tmp_line, tmp_line_strings, i, tmp_line->len));
	add_to_list(string, ft_strdup(";"));
	add_to_list(code, string);
}

void	handle_line(t_linked_list *tmp_line, t_linked_list *tmp_line_strings,
											t_linked_list *code, int current_indent)
{
	int				i;
	t_linked_list	*string;

	string = new_list();
	i = 0;
	while (i < current_indent)
	{
		add_to_list(string, ft_strdup("\t"));
		i++;
	}
	i = 0;
	while (i < tmp_line->len && *((char*)tmp_line->elts[i]) == INDENT)
	{
		add_to_list(string, ft_strdup("\t"));
		i++;
	}
	add_to_list(string, resolve_part(tmp_line, tmp_line_strings, i, tmp_line->len));
	add_to_list(string, ft_strdup(";"));
	add_to_list(code, list_to_string(string));
}

char	*function_to_c_code(t_linked_list *function, t_linked_list *func_strings)
{
	int				current_indent;
	int				i;
	char			returns;
	t_linked_list	*code;
	t_linked_list	*tmp_line;
	t_linked_list	*tmp_line_strings;
	t_linked_list	*created_vars;
	t_linked_list	*args_name;

	code = new_list();
	returns = does_function_return(function, func_strings);
	tmp_line = ((t_linked_list*)function->elts[0]);
	tmp_line_strings = ((t_linked_list*)func_strings->elts[0]);
	current_indent = get_line_indentation_level(tmp_line);
	add_to_list(code, get_function_prototype(tmp_line, tmp_line_strings, current_indent, returns));
	args_name = get_args_name(tmp_line, tmp_line_strings);
	created_vars = get_created_vars_in_function(function, func_strings, args_name);
	add_to_list(code, string_from_char_with_indent(current_indent, '{'));
	add_to_list(code, declare_created_variables(created_vars, current_indent + 1));
	// i = 1 to skip the first line, which is the function prototype
	i = 1;
	while (i < function->len)
	{
		tmp_line = ((t_linked_list*)function->elts[i]);
		tmp_line_strings = ((t_linked_list*)func_strings->elts[i]);
		handle_line(tmp_line, tmp_line_strings, code, current_indent);
		i++;
	}
	add_to_list(code, string_from_char_with_indent(current_indent, '}'));
	return (list_to_string_with_nl(code));
}

t_linked_list	*functions_to_c_code(t_linked_list *functions, t_linked_list *strings)
{
	t_linked_list	*code_functions;
	int				i;

	code_functions = new_list();
	i = 0;
	while (i < functions->len)
	{
		add_to_list(code_functions, function_to_c_code(((t_linked_list*)functions->elts[i]), ((t_linked_list*)strings->elts[i])));
		i++;
	}
	return (code_functions);
}
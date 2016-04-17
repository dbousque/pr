

#include "resolve_layer.h"

void	print_resolved_layer(t_linked_list *layer)
{
	int				i;
	int				x;
	t_linked_list	*tmp_line;

	i = 0;
	while (i < layer->len)
	{
		tmp_line = ((t_linked_list*)layer->elts[i]);
		x = 0;
		while (x < tmp_line->len)
		{
			if (*((char*)tmp_line->elts[x]) == FUNCTION_DECL)
				ft_putstr("FUNCTION_DECL");
			else if (*((char*)tmp_line->elts[x]) == EQUAL)
				ft_putstr("EQUAL");
			else if (*((char*)tmp_line->elts[x]) == COLON)
				ft_putstr("COLON");
			else if (*((char*)tmp_line->elts[x]) == COMMA)
				ft_putstr("COMMA");
			else if (*((char*)tmp_line->elts[x]) == OPEN_PAR)
				ft_putstr("OPEN_PAR");
			else if (*((char*)tmp_line->elts[x]) == CLOSE_PAR)
				ft_putstr("CLOSE_PAR");
			else if (*((char*)tmp_line->elts[x]) == OPEN_BRACKET)
				ft_putstr("OPEN_BRACKET");
			else if (*((char*)tmp_line->elts[x]) == CLOSE_BRACKET)
				ft_putstr("CLOSE_BRACKET");
			else if (*((char*)tmp_line->elts[x]) == OPEN_CURL_BRAC)
				ft_putstr("OPEN_CURL_BRAC");
			else if (*((char*)tmp_line->elts[x]) == CLOSE_CURL_BRAC)
				ft_putstr("CLOSE_CURL_BRAC");
			else if (*((char*)tmp_line->elts[x]) == POINT)
				ft_putstr("POINT");
			else if (*((char*)tmp_line->elts[x]) == SPACE)
				ft_putstr("SPACE");
			else if (*((char*)tmp_line->elts[x]) == TAB)
				ft_putstr("TAB");
			else if (*((char*)tmp_line->elts[x]) == NAME)
				ft_putstr("NAME");
			else if (*((char*)tmp_line->elts[x]) == FUNCTION_NAME)
				ft_putstr("FUNCTION_NAME");
			else if (*((char*)tmp_line->elts[x]) == KEYWORD)
				ft_putstr("KEYWORD");
			else if (*((char*)tmp_line->elts[x]) == INDENT)
				ft_putstr("INDENT");
			else if (*((char*)tmp_line->elts[x]) == STRING_DEF)
				ft_putstr("STRING_DEF");
			else if (*((char*)tmp_line->elts[x]) == CHARACTER_DEF)
				ft_putstr("CHARACTER_DEF");
			else if (*((char*)tmp_line->elts[x]) == INTEGER_DEF)
				ft_putstr("INTEGER_DEF");
			else if (*((char*)tmp_line->elts[x]) == FLOAT_DEF)
				ft_putstr("FLOAT_DEF");
			else if (*((char*)tmp_line->elts[x]) == DEEPCOPY_EQUAL)
				ft_putstr("DEEPCOPY_EQUAL");
			else if (*((char*)tmp_line->elts[x]) == EQUALITY_CHECK)
				ft_putstr("EQUALITY_CHECK");
			else if (*((char*)tmp_line->elts[x]) == DEEPCOPY)
				ft_putstr("DEEPCOPY");
			else if (*((char*)tmp_line->elts[x]) == COPY)
				ft_putstr("COPY");
			else if (*((char*)tmp_line->elts[x]) == COPY_EQUAL)
				ft_putstr("COPY_EQUAL");
			else if (*((char*)tmp_line->elts[x]) == OPERATION)
				ft_putstr("OPERATION");
			else if (*((char*)tmp_line->elts[x]) == VAR_NAME)
				ft_putstr("VAR_NAME");
			else
			{
				ft_putstr("\n\nUNKNOWN TYPE !\n");
				exit(1);
			}
			ft_putstr(",   ");
			x++;
		}
		ft_putstr("\n");
		i++;
	}
}

t_linked_list	*get_declared_functions(t_linked_list *abstracted_layer, t_linked_list *splitted_strings)
{
	int				x;
	int 			i;
	t_linked_list	*functions;
	t_linked_list	*line;
	t_linked_list	*line_strings;

	functions = new_list();
	x = 0;
	while (x < abstracted_layer->len)
	{
		line = ((t_linked_list*)abstracted_layer->elts[x]);
		line_strings = ((t_linked_list*)splitted_strings->elts[x]);
		i = 0;
		while (i < line->len && (*((char*)line->elts[i]) == TAB || *((char*)line->elts[i]) == SPACE))
			i++;
		if (*((char*)line->elts[i]) == FUNCTION_DECL)
		{
			if (i + 1 < line->len && *((char*)line->elts[i + 1]) == NAME)
				add_to_list(functions, ((char*)line_strings->elts[i + 1]));
			else
			{
				ft_putstr("Bad function declaration\n");
				exit(1);
			}
		}
		x++;
	}
	return (functions);
}

t_linked_list	*get_builtin_keywords(void)
{
	int				i;
	t_linked_list	*keywords;

	keywords = new_list();
	i = 0;
	while (i < NB_KEYWORDS)
	{
		add_to_list(keywords, KEYWORDS[i]);
		i++;
	}
	return (keywords);
}

void	print_declared_functions(t_linked_list *declared_functions)
{
	int		i;

	i = 0;
	while (i < declared_functions->len)
	{
		ft_putstr((char*)declared_functions->elts[i]);
		ft_putstr("\n");
		i++;
	}
}

void	add_builtin_functions_to_functions(t_linked_list *functions)
{
	int		i;

	i = 0;
	while (i < NB_BUILTIN_FUNCS)
	{
		add_to_list(functions, BUILTIN_FUNCS[i]);
		i++;
	}
}

char	string_in_list(char *string, t_linked_list *list)
{
	int		i;

	i = 0;
	while (i < list->len)
	{
		if (ft_strcmp(string, ((char*)list->elts[i])) == 0)
			return (1);
		i++;
	}
	return (0);
}

t_linked_list	*normalize_indentation(t_linked_list *resolved_layer, t_linked_list **strings)
{
	int				i;
	int				x;
	int				y;
	t_linked_list	*tmp_line;
	t_linked_list	*normalized;
	t_linked_list	*tmp_normalized;
	t_linked_list	*new_strings;
	t_linked_list	*tmp_strings;
	char			char_nb;
	char			*tmp_char;

	new_strings = new_list();
	normalized = new_list();
	char_nb = 0;
	i = 0;
	while (i < resolved_layer->len)
	{
		tmp_normalized = new_list();
		tmp_strings = new_list();
		tmp_line = ((t_linked_list*)resolved_layer->elts[i]);
		x = 0;
		while (x < tmp_line->len && (*((char*)tmp_line->elts[x]) == TAB || *((char*)tmp_line->elts[x]) == SPACE))
			x++;
		if (x != 0 && char_nb == 0)
			char_nb = x;
		y = 0;
		while (char_nb > 0 && y < x / char_nb)
		{
			if (!(tmp_char = (char*)malloc(sizeof(char))))
				malloc_error();
			*tmp_char = INDENT;
			add_to_list(tmp_normalized, tmp_char);
			add_to_list(tmp_strings, ft_strdup("\t"));
			y++;
		}
		while (x < tmp_line->len)
		{
			if (!(tmp_char = (char*)malloc(sizeof(char))))
				malloc_error();
			*tmp_char = *((char*)tmp_line->elts[x]);
			add_to_list(tmp_normalized, tmp_char);
			add_to_list(tmp_strings, ((char*)((t_linked_list*)(*strings)->elts[i])->elts[x]));
			x++;
		}
		add_to_list(normalized, tmp_normalized);
		add_to_list(new_strings, tmp_strings);
		i++;
	}
	*strings = new_strings;
	return (normalized);
}

char	string_is_string(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (str[0] == '"' && str[i - 1] == '"')
		return (1);
	return (0);
}

char	string_is_character(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (str[0] == '\'' && str[i - 1] == '\'')
		return (1);
	return (0);
}

char	string_is_integer(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

char	string_is_float(char *str)
{
	int		i;
	char	point_seen;

	point_seen = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (point_seen)
				return (0);
			point_seen = 1;
		}
		else if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (str[i - 1] == '.')
		return (0);
	return (1);
}

t_linked_list	*resolve_line(t_linked_list *line, t_linked_list *declared_functions,
							t_linked_list **splitted_strings_line, t_linked_list *builtin_keywords)
{
	int 			i;
	t_linked_list	*resolved_line;
	char			*to_add;
	char			*tmp_string;
	t_linked_list	*new_line_strings;

	new_line_strings = new_list();
	resolved_line = new_list();
	i = 0;
	while (i < line->len && (*((char*)line->elts[i]) == TAB || *((char*)line->elts[i]) == SPACE))
	{
		if (!(to_add = (char*)malloc(sizeof(char))))
			malloc_error();
		*to_add = *((char*)line->elts[i]);
		add_to_list(resolved_line, to_add);
		add_to_list(new_line_strings, ft_strdup("\t"));
		i++;
	}
	while (i < line->len)
	{
		if (!(to_add = (char*)malloc(sizeof(char))))
			malloc_error();
		*to_add = *((char*)line->elts[i]);
		tmp_string = ((char*)(*splitted_strings_line)->elts[i]);
		if (*((char*)line->elts[i]) == NAME)
		{
			if (i > 0 && *((char*)line->elts[i]) == FUNCTION_DECL)
				*to_add = FUNCTION_NAME;
			else if (string_in_list((*splitted_strings_line)->elts[i], declared_functions))
				*to_add = FUNCTION_NAME;
			else if (string_in_list((*splitted_strings_line)->elts[i], builtin_keywords))
				*to_add = KEYWORD;
			else if (string_is_string((*splitted_strings_line)->elts[i]))
				*to_add = STRING_DEF;
			else if (string_is_character((*splitted_strings_line)->elts[i]))
				*to_add = CHARACTER_DEF;
			else if (string_is_integer((*splitted_strings_line)->elts[i]))
				*to_add = INTEGER_DEF;
			else if (string_is_float((*splitted_strings_line)->elts[i]))
				*to_add = FLOAT_DEF;
			else
				*to_add = VAR_NAME;
		}
		else if (*((char*)line->elts[i]) == EQUAL && i + 1 < line->len && *((char*)line->elts[i + 1]) == EQUAL)
		{
			*to_add = EQUALITY_CHECK;
			tmp_string = ft_strdup("==");
			i++;
		}
		else if (*((char*)line->elts[i]) == COLON && i + 2 < line->len && *((char*)line->elts[i + 1]) == COLON
																		&& *((char*)line->elts[i + 2]) == EQUAL)
		{
			*to_add = DEEPCOPY_EQUAL;
			tmp_string = ft_strdup("::=");
			i += 2;
		}
		else if (*((char*)line->elts[i]) == COLON && i + 1 < line->len && *((char*)line->elts[i + 1]) == EQUAL)
		{
			*to_add = COPY_EQUAL;
			tmp_string = ft_strdup(":=");
			i++;
		}
		else if (*((char*)line->elts[i]) == COLON && i + 1 < line->len && *((char*)line->elts[i + 1]) == COLON)
		{
			*to_add = DEEPCOPY;
			tmp_string = ft_strdup("::");
			i++;
		}
		else if (*((char*)line->elts[i]) == COLON && i + 1 < line->len)
		{
			*to_add = COPY;
			tmp_string = ft_strdup(":");
		}
		add_to_list(resolved_line, to_add);
		add_to_list(new_line_strings, tmp_string);
		i++;
	}
	*splitted_strings_line = new_line_strings;
	return (resolved_line);
}

t_linked_list	*resolve_layer(t_linked_list *abstracted_layer, t_linked_list *splitted_strings)
{
	t_linked_list	*res;
	t_linked_list	*declared_functions;
	t_linked_list	*builtin_keywords;
	int				i;

	declared_functions = get_declared_functions(abstracted_layer, splitted_strings);
	builtin_keywords = get_builtin_keywords();
	add_builtin_functions_to_functions(declared_functions);
	print_declared_functions(declared_functions);
	res = new_list();
	i = 0;
	while (i < abstracted_layer->len)
	{
		add_to_list(res, resolve_line(((t_linked_list*)abstracted_layer->elts[i]), declared_functions,
							((t_linked_list**)splitted_strings->elts + i), builtin_keywords));
		i++;
	}
	res = normalize_indentation(res, &splitted_strings);
	print_resolved_layer(res);
	print_splitted_lines(splitted_strings);
	return (res);
}
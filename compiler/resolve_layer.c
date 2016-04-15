

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

t_linked_list	*resolve_line(t_linked_list *line, t_linked_list *declared_functions,
							t_linked_list *splitted_strings_line, t_linked_list *builtin_keywords)
{
	int 			i;
	t_linked_list	*resolved_line;
	char			*to_add;

	resolved_line = new_list();
	i = 0;
	while (i < line->len && (*((char*)line->elts[i]) == TAB || *((char*)line->elts[i]) == SPACE))
	{
		if (!(to_add = (char*)malloc(sizeof(char))))
			malloc_error();
		*to_add = *((char*)line->elts[i]);
		add_to_list(resolved_line, to_add);
		i++;
	}
	while (i < line->len)
	{
		if (!(to_add = (char*)malloc(sizeof(char))))
			malloc_error();
		*to_add = *((char*)line->elts[i]);
		if (*((char*)line->elts[i]) == NAME)
		{
			if (i > 0 && *((char*)line->elts[i]) == FUNCTION_DECL)
				*to_add = FUNCTION_NAME;
			else if (string_in_list(splitted_strings_line->elts[i], declared_functions))
				*to_add = FUNCTION_NAME;
			else if (string_in_list(splitted_strings_line->elts[i], builtin_keywords))
				*to_add = KEYWORD;
		}
		add_to_list(resolved_line, to_add);
		i++;
	}
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
							((t_linked_list*)splitted_strings->elts[i]), builtin_keywords));
		i++;
	}
	print_resolved_layer(res);
	return (abstracted_layer);
}


#include "resolve_layer.h"

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

t_linked_list	*resolve_line(t_linked_list *line, t_linked_list *declared_functions)
{
	int 	i;
	(void)line;
	(void)declared_functions;

	i = 0;
	while (i < line->len && (*((char*)line->elts[i]) == TAB || *((char*)line->elts[i]) == SPACE))
		i++;
	if (*((char*)line->elts[i]) == FUNCTION_DECL)
	{

	}
	return (line);
}

t_linked_list	*resolve_layer(t_linked_list *abstracted_layer, t_linked_list *splitted_strings)
{
	t_linked_list	*res;
	t_linked_list	*declared_functions;
	int				i;

	check_indentation(abstracted_layer);
	check_parentheses_and_brackets_close(abstracted_layer);
	declared_functions = get_declared_functions(abstracted_layer, splitted_strings);
	add_builtin_functions_to_functions(declared_functions);
	print_declared_functions(declared_functions);
	res = new_list();
	i = 0;
	while (i < abstracted_layer->len)
	{
		add_to_list(res, resolve_line(((t_linked_list*)abstracted_layer->elts[i]), declared_functions));
		i++;
	}
	(void)declared_functions;
	return (abstracted_layer);
}
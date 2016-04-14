

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
			add_to_list(functions, ((char*)line_strings->elts[i]));
		x++;
	}
	return (functions);
}

t_linked_list	*resolve_line(t_linked_list *line)
{
	int 	i;
	(void)line;

	i = 0;
	while (i < line->len && (*((char*)line->elts[i]) == TAB || *((char*)line->elts[i]) == SPACE))
		i++;
	if (*((char*)line->elts[i]) == FUNCTION_DECL)
	{

	}
	return (line);
}

void	check_indentation(t_linked_list *abstracted_layer)
{
	(void)abstracted_layer;
}

t_linked_list	*resolve_layer(t_linked_list *abstracted_layer, t_linked_list *splitted_strings)
{
	t_linked_list	*res;
	t_linked_list	*declared_functions;
	int				i;

	check_indentation(abstracted_layer);
	declared_functions = get_declared_functions(abstracted_layer, splitted_strings);
	res = new_list();
	i = 0;
	while (i < abstracted_layer->len)
	{
		add_to_list(res, resolve_line(((t_linked_list*)abstracted_layer->elts[i])));
		i++;
	}
	return (abstracted_layer);
}
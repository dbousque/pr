

#include "cut_into_functions.h"

void	print_functions(t_linked_list *functions)
{
	int		i;
	
	i = 0;
	while (i < functions->len)
	{
		ft_putstr("\n\nFunction n ");
		ft_putstr(ft_itoa(i + 1));
		ft_putstr(" :\n\n");
		print_resolved_layer(((t_linked_list*)functions->elts[i]));
		i++;
	}
}

void	print_functions_strings(t_linked_list *func_strings)
{
	int		i;

	i = 0;
	while (i < func_strings->len)
	{
		ft_putstr("\n\nFunction n ");
		ft_putstr(ft_itoa(i + 1));
		ft_putstr(" :\n\n");
		print_splitted_lines(((t_linked_list*)func_strings->elts[i]));
		i++;
	}
}

static int		get_line_indentation_level(t_linked_list *line)
{
	int		i;

	i = 0;
	while (i < line->len && *((char*)line->elts[i]) == INDENT)
		i++;
	return (i);
}

t_linked_list	*cut_into_functions(t_linked_list *resolved_layer, t_linked_list **strings)
{
	t_linked_list	*functions;
	t_linked_list	*tmp_function;
	int				i;
	int				x;
	t_linked_list	*tmp_line;
	int				current_indent_level;
	t_linked_list	*new_strings;
	t_linked_list	*tmp_line_string;
	t_linked_list	*tmp_func_strings;

	new_strings = new_list();
	functions = new_list();
	i = 0;
	while (i < resolved_layer->len)
	{
		tmp_line = ((t_linked_list*)resolved_layer->elts[i]);
		tmp_line_string = ((t_linked_list*)(*strings)->elts[i]);
		x = get_line_indentation_level(tmp_line);
		if (*((char*)tmp_line->elts[x]) == FUNCTION_DECL && *((char*)tmp_line->elts[x + 1]) == FUNCTION_NAME)
		{
			current_indent_level = x;
			tmp_function = new_list();
			tmp_func_strings = new_list();
			add_to_list(tmp_function, tmp_line);
			add_to_list(tmp_func_strings, tmp_line_string);
			i++;
			while (i < resolved_layer->len)
			{
				tmp_line = ((t_linked_list*)resolved_layer->elts[i]);
				tmp_line_string = ((t_linked_list*)(*strings)->elts[i]);
				if (get_line_indentation_level(tmp_line) > current_indent_level)
				{
					add_to_list(tmp_function, tmp_line);
					add_to_list(tmp_func_strings, tmp_line_string);
					if (i == resolved_layer->len - 1)
					{
						add_to_list(functions, tmp_function);
						add_to_list(new_strings, tmp_func_strings);
					}
				}
				else
				{
					add_to_list(functions, tmp_function);
					add_to_list(new_strings, tmp_func_strings);
					break ;
				}
				i++;
			}
		}
		else
		{
			ft_putstr("line not in a function !!! Should not happen for now\n");
			exit(1);
		}
	}
	*strings = new_strings;
	print_functions(functions);
	print_functions_strings(new_strings);
	return (functions);
}
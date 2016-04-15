

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

int			get_line_indentation_level(t_linked_list *line)
{
	int		i;

	i = 0;
	while (i < line->len && *((char*)line->elts[i]) == INDENT)
		i++;
	return (i);
}

t_linked_list	*cut_into_functions(t_linked_list *resolved_layer)
{
	t_linked_list	*functions;
	t_linked_list	*tmp_function;
	int				i;
	int				x;
	t_linked_list	*tmp_line;
	int				current_indent_level;

	functions = new_list();
	i = 0;
	while (i < resolved_layer->len)
	{
		tmp_line = ((t_linked_list*)resolved_layer->elts[i]);
		x = get_line_indentation_level(tmp_line);
		if (*((char*)tmp_line->elts[x]) == FUNCTION_DECL && *((char*)tmp_line->elts[x + 1]) == FUNCTION_NAME)
		{
			current_indent_level = x;
			tmp_function = new_list();
			add_to_list(tmp_function, tmp_line);
			i++;
			while (i < resolved_layer->len)
			{
				tmp_line = ((t_linked_list*)resolved_layer->elts[i]);
				if (get_line_indentation_level(tmp_line) > current_indent_level)
				{
					add_to_list(tmp_function, tmp_line);
					if (i == resolved_layer->len - 1)
						add_to_list(functions, tmp_function);
				}
				else
				{
					add_to_list(functions, tmp_function);
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
	print_functions(functions);
	return (functions);
}
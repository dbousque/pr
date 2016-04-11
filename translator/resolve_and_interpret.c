

#include "resolve_and_interpret.h"

void	resolve_and_interpret_line(t_linked_list *instructions, t_linked_list *strings)
{
	print_linked_list_nl(instructions);
	print_linked_list_nl(strings);
}

void	resolve_and_interpret(t_linked_list *instructions, t_linked_list *strings)
{
	print_linked_list_nl(instructions);
	print_linked_list_nl(strings);
	int		i;

	i = 0;
	while (i < instructions->len)
	{
		resolve_and_interpret_line(((t_variable*)instructions->elts[i])->val, ((t_variable*)strings->elts[i])->val);
		i++;
	}
}
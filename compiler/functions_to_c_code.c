

#include "functions_to_c_code.h"

char	*function_to_c_code(t_linked_list *function)
{
	(void)function;
	return ((char*)function);
}

t_linked_list	*functions_to_c_code(t_linked_list *functions)
{
	t_linked_list	*code_functions;
	int				i;

	code_functions = new_list();
	i = 0;
	while (i < functions->len)
	{
		add_to_list(code_functions, function_to_c_code(((t_linked_list*)functions->elts[i])));
		i++;
	}
	return (code_functions);
}


#include "variable.h"

t_variable	*new_var(char type)
{
	t_variable	*var;

	if (!(var = (t_variable*)malloc(sizeof(t_variable))))
		malloc_error();
	var->type = type;
	return (var);
}

t_variable	*new_var_from_string(t_string *string)
{
	t_variable	*var;

	var = new_var(STRING);
	var->val = string;
	return (var);
}

t_variable	*new_var_from_list(t_linked_list *list)
{
	t_variable	*var;

	var = new_var(LINKED_LIST);
	var->val = list;
	return (var);
}
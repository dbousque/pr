

#include "variable.h"

t_variable	*new_var(char type)
{
	t_variable	*var;

	if (!(var = (t_variable*)malloc(sizeof(t_variable))))
		malloc_error();
	var->type = type;
	return (var);
}
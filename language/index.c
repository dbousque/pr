

#include "index.h"

t_variable	*_index(t_variable *var, t_variable *ind)
{
	if (var->type == LINKED_LIST)
		return (index_linked_list(var->val, *((int*)ind->val)));
	else if (var->type == STRING)
		return (index_string(var->val, *((int*)ind->val)));
	return (NULL);
}

t_variable	*index_linked_list(t_linked_list *list, long ind)
{
	return ((t_variable*)list->elts[ind]);
}

t_variable	*index_string(t_string *string, long ind)
{
	t_variable	*res;

	res = new_var(CHAR);
	*((char*)res->val) = string->chars[ind];
	return (res);
}


#include "minus.h"

t_variable	*_minus(t_variable *var1, t_variable *var2)
{
	if (var1->type == INT && var2->type == INT)
		return (_new_int(*(int*)var1->val - *(int*)var2->val));
	return (NULL);
}
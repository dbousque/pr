

#include "plus_equal.h"

void	_plus_equal(t_variable *var1, t_variable *var2)
{
	if (var1->type == INT && var2->type == INT)
		*(int*)var1->val += *(int*)var2->val;
}
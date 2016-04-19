

#include "is_less.h"

char	_is_less(t_variable *var1, t_variable *var2)
{
	if (var1->type == INT && var2->type == INT)
	{
		if (*(int*)var1->val < *(int*)var2->val)
			return (1);
		return (0);
	}
	return (0);
}
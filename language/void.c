

#include "void.h"

t_variable	*_new_void(void)
{
	t_variable	*res_var = new_var(VOID);
	if (!(res_var->val = (int*)malloc(sizeof(int))))
		malloc_error();
	return (res_var);
}
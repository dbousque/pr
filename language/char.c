

#include "char.h"


t_variable	*_new_char(char c)
{
	t_variable	*res_var = new_var(CHAR);
	if (!(res_var->val = (char*)malloc(sizeof(char))))
		malloc_error();
	*((char*)res_var->val) = c;
	return (res_var);
}
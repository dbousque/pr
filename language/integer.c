

#include "integer.h"


t_variable	*_new_int(int n)
{
	t_variable	*res_var = new_var(INT);
	if (!(res_var->val = (int*)malloc(sizeof(int))))
		malloc_error();
	*((int*)res_var->val) = n;
	return (res_var);
}

t_variable	*_new_int_from_chars(char *str, long len)
{
	t_variable	*res_var = new_var(INT);
	if (!(res_var->val = (int*)malloc(sizeof(int))))
		malloc_error();
	*((int*)res_var->val) = ft_atoi_with_size(str, len);
	return (res_var);
}

t_variable	*_new_int_from_string(t_string *string)
{
	return (_new_int_from_chars(string->chars, string->len));
}
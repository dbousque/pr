

#include "string.h"

t_variable	*_new_void_string(void)
{
	t_variable	*res_var = new_var(STRING);
	res_var->val = new_void_string();
	return (res_var);
}

t_string	*new_void_string(void)
{
	t_string	*res;

	if (!(res = (t_string*)malloc(sizeof(t_string))))
		malloc_error();
	res->len = 0;
	res->size = 0;
	res->freeable = 1;
	return (res);
}


t_variable	*_new_string(void)
{
	t_variable	*res_var = new_var(STRING);
	res_var->val = new_string();
	return (res_var);
}

t_string	*new_string(void)
{
	t_string	*res;

	if (!(res = (t_string*)malloc(sizeof(t_string))))
		malloc_error();
	if (!(res->chars = (char*)malloc(sizeof(char) * NEW_STRING_EXTRA_CHARS)))
		malloc_error();
	res->size = NEW_STRING_EXTRA_CHARS;
	res->len = 0;
	res->freeable = 1;
	return (res);
}


t_variable	*_new_string_of_size(long size)
{
	t_variable	*res_var = new_var(STRING);
	res_var->val = new_string_of_size(size);
	return (res_var);
}

t_string	*new_string_of_size(long size)
{
	t_string	*res;

	size += NEW_STRING_EXTRA_CHARS;
	if (!(res = (t_string*)malloc(sizeof(t_string))))
		malloc_error();
	if (!(res->chars = (char*)malloc(sizeof(char) * size)))
		malloc_error();
	res->size = size;
	res->len = 0;
	res->freeable = 1;
	return (res);
}


t_variable	*_new_string_from_chars(char *str, long len)
{
	t_variable	*res_var = new_var(STRING);
	res_var->val = new_string_from_chars(str, len);
	return (res_var);
}

t_string	*new_string_from_chars(char *str, long len)
{
	t_string	*res;

	res = new_void_string();
	res->freeable = 0;
	set_string_chars(res, str, len);
	return (res);
}


void	_set_string_chars(t_string *string, char *chars, long len)
{
	set_string_chars(string, chars, len);
}

void	set_string_chars(t_string *string, char *chars, long len)
{
	string->chars = chars;
	string->len = len;
	string->size = len;
}


t_variable	*_cpy_string(t_string *string)
{
	t_variable	*res_var = new_var(STRING);
	res_var->val = cpy_string(string);
	return (res_var);
}

t_string	*cpy_string(t_string *string)
{
	t_string	*res;

	if (!(res = (t_string*)malloc(sizeof(t_string))))
		malloc_error();
	if (!(res->chars = (char*)malloc(sizeof(char) * string->size)))
		malloc_error();
	res->size = string->size;
	res->len = 0;
	res->freeable = 1;
	while (res->len < string->len)
	{
		res->chars[res->len] = string->chars[res->len];
		res->len++;
	}
	return (res);
}


void	empty_string(t_string *string)
{
	string->len = 0;
}


void	free_string(t_string *string)
{
	if (string->freeable)
		free(string->chars);
	free(string);
}
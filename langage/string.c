

#include "string.h"

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

void	set_string_chars(t_string *string, char *chars, long len)
{
	string->chars = chars;
	string->len = len;
	string->size = len;
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
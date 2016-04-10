

#include "string_utils.h"


static void	double_string_size(t_string *str)
{
	char	*new_chars;
	long	i;

	str->size = (str->size > 0 ? str->size * 2 : 1 + NEW_STRING_EXTRA_CHARS);
	if (!(new_chars = (char*)malloc(sizeof(char) * (str->size))))
		malloc_error();
	i = 0;
	while (i < str->len)
	{
		new_chars[i] = str->chars[i];
		i++;
	}
	if (str->freeable)
		free(str->chars);
	else
		str->freeable = 1;
	str->chars = new_chars;
}


void	_concat_strings(t_variable *str1, t_variable *str2)
{
	concat_strings(str1->val, str2->val);
}

void	concat_strings(t_string *str1, t_string *str2)
{
	long	i;
	long	start;

	while (str1->size < str1->len + str2->len)
		double_string_size(str1);
	i = 0;
	start = str1->len;
	while (i < str2->len)
	{
		str1->chars[start] = str2->chars[i];
		i++;
		start++;
	}
	str1->len = start;
}


t_variable	*_add_strings(t_variable *str1, t_variable *str2)
{
	t_variable	*res_var = new_var(STRING);
	res_var->val = add_strings(str1->val, str2->val);
	return (res_var);
}

t_string	*add_strings(t_string *str1, t_string *str2)
{
	t_string	*res;
	long		i;

	if (!(res = (t_string*)malloc(sizeof(t_string))))
		malloc_error();
	res->size = str1->size + str2->size;
	if (!(res->chars = (char*)malloc(sizeof(char) * res->size)))
		malloc_error();
	i = 0;
	while (i < str1->len)
	{
		res->chars[i] = str1->chars[i];
		i++;
	}
	res->len = i;
	while (res->len < str1->len + str2->len)
	{
		res->chars[res->len] = str2->chars[res->len - i];
		res->len++;
	}
	return (res);
}


t_variable	*_get_substring(t_variable *str, t_variable *start, t_variable *end)
{
	long	_start = (start->type == INT ? *((int*)start->val) : *((long*)start->val));
	long	_end = (end->type == INT ? *((int*)end->val) : *((long*)end->val));
	t_variable	*res_var = new_var(STRING);
	res_var->val = get_substring(str->val, _start, _end);
	return (res_var);
}

t_string	*get_substring(t_string *str, long start, long end)
{
	t_string	*res;

	if (!(res = (t_string*)malloc(sizeof(t_string))))
		malloc_error();
	res->chars = str->chars + start;
	res->len = end - start;
	res->size = end - start;
	res->freeable = 0;
	return (res);
}


static void		get_splitted_start_indexes(t_string *string, t_linked_list *indexes, long i, char to_split)
{
	long			*tmp_ind;
	char			in_content;

	if (!(tmp_ind = (long*)malloc(sizeof(long))))
		malloc_error();
	*tmp_ind = i;
	while (i < string->len)
	{
		if (string->chars[i] == to_split)
		{
			if (in_content)
				in_content = 0;
		}
		else if (!in_content)
		{
			if (!(tmp_ind = (long*)malloc(sizeof(long))))
				malloc_error();
			*tmp_ind = i;
			add_to_list(indexes, (void*)tmp_ind);
			in_content = 1;
		}
		i++;
	}
}


t_variable	*_split_string(t_variable *string, t_variable *to_split)
{
	t_variable	*res_var = new_var(LINKED_LIST);
	res_var->val = split_string(string->val, *((char*)to_split->val));
	return (res_var);
}

// This could be done faster, no need to get the indexes first,
// since it uses a linked_list too, so it is not faster to fetch the indexes first
t_linked_list	*split_string(t_string *string, char to_split)
{
	t_linked_list	*res;
	t_linked_list	*indexes;
	long			i;
	long			end;
	long			ori_end;
	long			start;
	t_string		*tmp_string;

	indexes = new_list();
	i = 0;
	while (i < string->len && string->chars[i] == to_split)
		i++;
	if (i == string->len)
		return (indexes);
	get_splitted_start_indexes(string, indexes, i, to_split);
	res = new_list_start_size(indexes->len);
	i = 0;
	while (i < indexes->len)
	{
		start = *((long*)indexes->elts[i]);
		if (i == indexes->len - 1)
			end = string->len;
		else
			end = *((long*)indexes->elts[i + 1]);
		end--;
		ori_end = end;
		while (end > start && string->chars[end] == to_split)
			end--;
		tmp_string = new_void_string();
		tmp_string->freeable = 0;
		tmp_string->chars = string->chars + start;
		tmp_string->size = ori_end - start + 1;
		tmp_string->len = end - start + 1;
		add_to_list(res, (void*)tmp_string);
		i++;
	}
	free_list(indexes);
	return (res);
}


void	_replace_subpart(t_variable *string, t_variable *start, t_variable *end, t_variable *to_add)
{
	long	_start = (start->type == INT ? *((int*)start->val) : *((long*)start->val));
	long	_end = (end->type == INT ? *((int*)end->val) : *((long*)end->val));
	replace_subpart(string->val, _start, _end, ((t_string*)to_add->val)->chars, ((t_string*)to_add->val)->len);
}

void	replace_subpart(t_string *string, long start, long end, char *to_add, long to_add_len)
{
	long	i;
	long	x;

	while (string->size - string->len + (end - start) < to_add_len)
		double_string_size(string);
	if (to_add_len != end - start)
	{
		x = to_add_len - (end - start);
		if (x > 0)
		{
			i = string->len - 1;
			while (i >= end)
			{
				string->chars[i + x] = string->chars[i];
				i--;
			}
		}
		else
		{
			i = start + to_add_len;
			while (i < string->len)
			{
				string->chars[i + x] = string->chars[i];
				i++;
			}
		}
	}
	i = start;
	while (i < end)
	{
		string->chars[i] = to_add[i - start];
		i++;
	}
}



// Estimate boolean values of variables with a is_true(var) function
// ex :   if (is_true(_char_in_string()))
// and    char   is_true(t_variable *var)
//		  {
//			if (var->type == CHAR) return *((char*)var->val) != 0;
//		  }

t_variable	*_char_in_string(t_variable *c, t_variable *str)
{
	t_variable	*res = new_var(CHAR);
	if (!(*res->val = (char*)malloc(sizeof(char))))
		malloc_error();
	*res->val = char_in_string(*((char*)c->val), ((t_string*)str->val)->chars, ((t_string*)str->val)->len);
	return (res_var);
}

char	char_in_string(char c, char *str, long str_len)
{
	long	i;

	i = 0;
	while (i < str_len)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}


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

void	concat_strings(t_string *str1, t_string *str2)
{
	long	i;
	long	start;

	while (str1->size < str1->len + str2->len)
		double_string_size(str1);
	i = str1->len;
	start = str1->len;
	while (i < str2->len)
	{
		str1->chars[start] = str2->chars[i];
		i++;
		start++;
	}
	str1->len = start;
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


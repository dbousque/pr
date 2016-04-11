

#include "keyword_in.h"


// Estimate boolean values of variables with a is_true(var) function
// ex :   if (is_true(_char_in_string()))
// and    char   is_true(t_variable *var)
//		  {
//			if (var->type == CHAR) return *((char*)var->val) != 0;
//		  }

t_variable	*_char_in_string(t_variable *c, t_variable *str)
{
	return (_new_char(char_in_string(*((char*)c->val), ((t_string*)str->val)->chars, ((t_string*)str->val)->len)));
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


t_variable	*_string_in_linked_list(t_variable *string, t_variable *list)
{
	return (_new_char(string_in_linked_list(string->val, list->val)));
}

char	string_in_linked_list(t_string *string, t_linked_list *list)
{
	long	i;

	i = 0;
	while (i < list->len)
	{
		if (((t_variable*)list->elts[i])->type == STRING && equals_strings(string, ((t_variable*)list->elts[i])->val))
			return (1);
		i++;
	}
	return (0);
}

char	string_in_chartab(t_string *string, char **list, long list_len)
{
	t_linked_list	*linked_list;
	long			i;

	linked_list = new_list();
	i = 0;
	while (i < list_len)
	{
		add_to_list(linked_list, _new_string_from_chars(list[i], ft_strlen(list[i])));
		i++;
	}
	return (string_in_linked_list(string, linked_list));
}
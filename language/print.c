

#include "print.h"

void	printn(t_variable *var)
{
	int		lol;

	if (var->type == LINKED_LIST)
		print_linked_list(var->val);
	else if (var->type == STRING)
		print_string(var->val);
	else if (var->type == CHAR)
		print_char(var);
	else if (var->type == INT)
		print_int(var);
	else if (var->type == VOID)
		lol = write(1, "void", 4);
	else
	{
		lol = write(1, "NOT FOUND\n", 10);
	}
	(void)lol;
}

void	print(t_variable *var)
{
	printn(var);
	int lol = write(1, "\n", 1);
	(void)lol;
}

void	print_raw_chars(char *str)
{
	int lol = write(1, str, ft_strlen(str));
	(void)lol;
}

void	print_chars(char *str)
{
	print_raw_chars(str);
	int lol = write(1, "\n", 1);
	(void)lol;
}

void	print_chars_of_size(char *str, long len)
{
	int lol = write(1, str, len);
	lol = write(1, "\n", 1);
	(void)lol;
}

void	print_string(t_string *string)
{
	int lol = write(1, string->chars, string->len);
	(void)lol;
}

void	print_string_nl(t_string *string)
{
	print_string(string);
	int lol = write(1, "\n", 1);
	(void)lol;
}

void	print_linked_list(t_linked_list *list)
{
	long	i;
	int		lol;

	i = 0;
	lol = write(1, "[", 1);

	while (i < list->len)
	{
		if (((t_variable*)list->elts[i])->type == STRING)
			lol = write(1, "\"", 1);
		printn(list->elts[i]);
		if (((t_variable*)list->elts[i])->type == STRING)
			lol = write(1, "\"", 1);
		if (i != list->len - 1)
			lol = write(1, ", ", 2);
		i++;
	}
	lol = write(1, "]", 1);
	(void)lol;
}

void	print_linked_list_nl(t_linked_list *list)
{
	print_linked_list(list);
	int lol = write(1, "\n", 1);
	(void)lol;
}

void	print_char(t_variable *var)
{
	char	*str;

	str = ft_itoa(*((char*)var->val));
	int lol = write(1, str, ft_strlen(str));
	(void)lol;
}

void	print_int(t_variable *var)
{
	char	*str;

	str = ft_itoa(*((int*)var->val));
	int lol = write(1, str, ft_strlen(str));
	(void)lol;
}
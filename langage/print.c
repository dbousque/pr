

#include "print.h"

long	ft_strlen(char *str)
{
	long	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_raw_chars(char *str)
{
	write(1, str, ft_strlen(str));
}

void	print_chars(char *str)
{
	print_raw_chars(str);
	write(1, "\n", 1);
}

void	print_raw(t_string *string)
{
	write(1, string->chars, string->len);
}

void	print(t_string *string)
{
	print_raw(string);
	write(1, "\n", 1);
}
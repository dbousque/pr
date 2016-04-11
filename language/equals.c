

#include "equals.h"


t_variable	*_equals(t_variable *var1, t_variable *var2)
{
	if (var1->type == STRING && var2->type == STRING)
		return (_new_char(equals_strings(var1->val, var2->val)));
	return (NULL);
}


char	equals_strings(t_string *str1, t_string *str2)
{
	if (str1->len != str2->len)
		return (0);
	long	i;

	i = 0;
	while (i < str1->len)
	{
		if (str1->chars[i] != str2->chars[i])
			return (0);
		i++;
	}
	return (1);
}


char	equals_chars(char *str1, char *str2, long len1, long len2)
{
	if (len1 != len2)
		return (0);
	long	i;

	i = 0;
	while (i < len1)
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}


#include "resolve_part.h"

/*#define TYPE_VALUE 1
#define TYPE_COMPLEX 2

typedef struct	s_value
{
	char		type;
	char		*repr;
}				t_value;*/

typedef struct	s_expression
{
	char		type;

}				t_expression;

int		get_end_of_expression(t_linked_list *line, int start)
{
	char	end_char;
	int		i;
	int		count;

	count = 0;
	end_char = '\0';
	if (*((char*)line->elts[start]) == OPEN_PAR)
		end_char = CLOSE_PAR;
	else if (*((char*)line->elts[start]) == OPEN_BRACKET)
		end_char = CLOSE_BRACKET;
	else if (*((char*)line->elts[start]) == OPEN_CURL_BRAC)
		end_char = CLOSE_CURL_BRAC;
	i = start;
	while (i < line->len)
	{
		if (*((char*)line->elts[i]) == end_char)
		{
			count--;
			if (count == 0)
				return (i + 1);
		}
		else if (end_char && *((char*)line->elts[i]) == *((char*)line->elts[start]))
			count++;
		i++;
	}
	return (i);
}

char	function_is_builtin(char *string)
{
	int		i;

	i = 0;
	while (i < NB_BUILTIN_FUNCS)
	{
		if (ft_strcmp(string, BUILTIN_FUNCS[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

char	*resolve_part(t_linked_list *line, t_linked_list *line_strings, int start, int end)
{
	t_linked_list	*strings;

	if (start >= end - 1)
		return (ft_strdup(""));
	strings = new_list();
	if (*((char*)line->elts[start]) == FUNCTION_NAME)
	{
		if (function_is_builtin((char*)line_strings->elts[start]))
			add_to_list(strings, ft_strdup("_"));
		else
			add_to_list(strings, ft_strdup("__"));
		add_to_list(strings, (char*)line_strings->elts[start]);
		add_to_list(strings, resolve_part(line, line_strings, start + 1, end));
		add_to_list(strings, ft_strdup(";"));
	}
	else if (*((char*)line->elts[start]) == OPEN_PAR)
	{
		add_to_list(strings, ft_strdup("("));
		// when a parenthese is given to start, we assume end points to the relating closing parenthese, so end - 1
		add_to_list(strings, resolve_part(line, line_strings, start + 1, end - 1));
		add_to_list(strings, ft_strdup(")"));
	}
	else if (*((char*)line->elts[start]) == )
	return (list_to_string(strings));
}
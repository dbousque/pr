

#include "resolve_part.h"

typedef struct	s_line
{
	
}				t_line;

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

char	*get_c_function_name(char *function_name)
{
	int		i;

	i = 0;
	while (i < NB_BUILTIN_FUNCS)
	{
		if (ft_strcmp(function_name, BUILTIN_FUNCS[i]) == 0)
			return (BUILTIN_FUNCS_IN_C[i]);
		i++;
	}
	return (NULL);
}

char	*resolve_part(t_linked_list *line, t_linked_list *line_strings, int start, int end)
{
	FILE			*fp;
	t_linked_list	*tmp_command;
	int				i;
	char			out[100];
	
	(void)start;
	(void)end;
	tmp_command = new_list();
	add_to_list(tmp_command, ft_strdup("echo \""));
	i = 0;
	while (*((char*)line->elts[i]) == INDENT)
		i++;
	while (i < line->len)
	{
		if (*((char*)line->elts[i]) == FUNCTION_NAME)
		{
			if (function_is_builtin((char*)line_strings->elts[i]))
				add_to_list(tmp_command, get_c_function_name((char*)line_strings->elts[i]));
			else
			{
				add_to_list(tmp_command, ft_strdup("__"));
				add_to_list(tmp_command, (char*)line_strings->elts[i]);
			}
		}
		else
			add_to_list(tmp_command, (char*)line_strings->elts[i]);
		add_to_list(tmp_command, ft_strdup(" "));
		i++;
	}
	add_to_list(tmp_command, ft_strdup(";\" | ./grammar/a.out"));
	printf("command : %s\n", list_to_string(tmp_command));
	fp = popen(list_to_string(tmp_command), "r");
	fgets(out, 100, fp);
	printf("RESULT : %s\n", out);
	return (ft_strdup(out));
}
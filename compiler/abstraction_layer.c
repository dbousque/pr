

#include "abstraction_layer.h"

char	char_in_str(char c, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*interpret_string(char *string)
{
	char	*res;

	if (!(res = (char*)malloc(sizeof(char))))
		malloc_error();
	if (ft_strcmp(string, STR_FUNCTION_DECL) == 0)
		*res = FUNCTION_DECL;
	else if (ft_strcmp(string, STR_EQUAL) == 0)
		*res = EQUAL;
	else if (ft_strcmp(string, STR_COLON) == 0)
		*res = COLON;
	else if (ft_strcmp(string, STR_COMMA) == 0)
		*res = COMMA;
	else if (ft_strcmp(string, STR_OPEN_PAR) == 0)
		*res = OPEN_PAR;
	else if (ft_strcmp(string, STR_CLOSE_PAR) == 0)
		*res = CLOSE_PAR;
	else if (ft_strcmp(string, STR_OPEN_BRACKET) == 0)
		*res = OPEN_BRACKET;
	else if (ft_strcmp(string, STR_CLOSE_BRACKET) == 0)
		*res = CLOSE_BRACKET;
	else if (ft_strcmp(string, STR_OPEN_CURL_BRAC) == 0)
		*res = OPEN_CURL_BRAC;
	else if (ft_strcmp(string, STR_CLOSE_CURL_BRAC) == 0)
		*res = CLOSE_CURL_BRAC;
	else if (ft_strcmp(string, STR_POINT) == 0)
		*res = POINT;
	else if (ft_strcmp(string, STR_SPACE) == 0)
		*res = SPACE;
	else if (ft_strcmp(string, STR_TAB) == 0)
		*res = TAB;
	else if (char_in_str(string[0], STR_OPERATION))
		*res = OPERATION;
	else
		*res = NAME;
	return (res);
}

void	print_layer(t_linked_list *layer)
{
	int				i;
	int				x;
	t_linked_list	*tmp_line;

	i = 0;
	while (i < layer->len)
	{
		tmp_line = ((t_linked_list*)layer->elts[i]);
		x = 0;
		while (x < tmp_line->len)
		{
			if (*((char*)tmp_line->elts[x]) == FUNCTION_DECL)
				ft_putstr("FUNCTION_DECL");
			else if (*((char*)tmp_line->elts[x]) == EQUAL)
				ft_putstr("EQUAL");
			else if (*((char*)tmp_line->elts[x]) == COLON)
				ft_putstr("COLON");
			else if (*((char*)tmp_line->elts[x]) == COMMA)
				ft_putstr("COMMA");
			else if (*((char*)tmp_line->elts[x]) == OPEN_PAR)
				ft_putstr("OPEN_PAR");
			else if (*((char*)tmp_line->elts[x]) == CLOSE_PAR)
				ft_putstr("CLOSE_PAR");
			else if (*((char*)tmp_line->elts[x]) == OPEN_BRACKET)
				ft_putstr("OPEN_BRACKET");
			else if (*((char*)tmp_line->elts[x]) == CLOSE_BRACKET)
				ft_putstr("CLOSE_BRACKET");
			else if (*((char*)tmp_line->elts[x]) == OPEN_CURL_BRAC)
				ft_putstr("OPEN_CURL_BRAC");
			else if (*((char*)tmp_line->elts[x]) == CLOSE_CURL_BRAC)
				ft_putstr("CLOSE_CURL_BRAC");
			else if (*((char*)tmp_line->elts[x]) == POINT)
				ft_putstr("POINT");
			else if (*((char*)tmp_line->elts[x]) == SPACE)
				ft_putstr("SPACE");
			else if (*((char*)tmp_line->elts[x]) == TAB)
				ft_putstr("TAB");
			else if (*((char*)tmp_line->elts[x]) == NAME)
				ft_putstr("NAME");
			else if (*((char*)tmp_line->elts[x]) == OPERATION)
				ft_putstr("OPERATION");
			else
			{
				ft_putstr("\n\nUNKNOWN TYPE !\n");
				exit(1);
			}
			ft_putstr(",   ");
			x++;
		}
		ft_putstr("\n");
		i++;
	}
}

t_linked_list	*make_abstraction_layer(t_linked_list *splitted_lines)
{
	t_linked_list	*res;
	int				i;
	int				x;
	t_linked_list	*tmp_line;
	t_linked_list	*tmp_res_line;

	res = new_list();
	print_splitted_lines(splitted_lines);
	i = 0;
	while (i < splitted_lines->len)
	{
		x = 0;
		tmp_res_line = new_list();
		tmp_line = ((t_linked_list*)splitted_lines->elts[i]);
		while (x < tmp_line->len)
		{
			add_to_list(tmp_res_line, interpret_string(tmp_line->elts[x]));
			x++;
		}
		add_to_list(res, tmp_res_line);
		i++;
	}
	print_layer(res);
	return (res);
}
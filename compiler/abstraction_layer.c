

#include "abstraction_layer.h"

char	*interpret_string(char *string)
{
	char	*res;

	if (!(res = (char*)malloc(sizeof(char))))
		malloc_error();

	if (ft_strcmp(string, FUNCTION_DECL))
		*res = 
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
	return (res);
}


#include "parser.h"

typedef struct	s_linked_list
{
	void		**elts;
	int			len;
	int			size;
}				t_linked_list;

t_linked_list	*new_list(void)
{
	t_linked_list	*res;

	if (!(res = (t_linked_list*)malloc(sizeof(t_linked_list))))
		malloc_error();
	if (!(res->elts = (void**)malloc(sizeof(void*) * 2)))
		malloc_error();
	res->len = 0;
	res->size = 2;
	return (res);
}

static void		double_list_size(t_linked_list *list)
{
	int		i;
	void	**new_elts;

	list->size *= 2;
	if (!(new_elts = (void**)malloc(sizeof(void*) * list->size)))
		malloc_error();
	i = 0;
	while (i < list->len)
	{
		new_elts[i] = list->elts[i];
		i++;
	}
	free(list->elts);
	list->elts = new_elts;
}

void	add_to_list(t_linked_list *list, void *elt)
{
	if (list->len == list->size)
		double_list_size(list);
	list->elts[list->len] = elt;
	list->len++;
}

t_linked_list	*parse_line(char *line)
{
	int				i;
	t_linked_list	*res;
}

void	parse(char *file_content, long file_len)
{
	char			**lines;
	int				i;
	t_linked_list	*splitted_lines;

	lines = split_on_char(file_content, file_len, '\n');
	splitted_lines = new_list();
	i = 0;
	while (lines[i])
	{
		ft_putstr(lines[i]);
		write(1, "\n\n", 2);
		add_to_list(splitted_lines, parse_line(lines[i]));
		i++;
	}
}


#include "resolve_layer.h"

t_linked_list	*resolve_line(t_linked_list *line)
{
	(void)line;
	return (line);
}

t_linked_list	*resolve_layer(t_linked_list *abstracted_layer)
{
	t_linked_list	*res;
	int				i;

	res = new_list();
	i = 0;
	while (i < abstracted_layer->len)
	{
		add_to_list(res, resolve_line(((t_linked_list*)abstracted_layer->elts[i])));
		i++;
	}
}
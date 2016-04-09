

#include "linked_list.h"

t_linked_list	*new_list_start_size(long start_size)
{
	t_linked_list	*res;

	if (!(res = (t_linked_list*)malloc(sizeof(t_linked_list))))
		malloc_error();
	if (!(res->elts = (void**)malloc(sizeof(void*) * start_size)))
		malloc_error();
	res->size = start_size;
	res->len = 0;
	return (res);
}

t_linked_list	*new_list(void)
{
	return (new_list_start_size(LINKED_LIST_START_SIZE));
}

static void	double_list_size(t_linked_list *list)
{
	void	**new_elts;
	long	i;

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

void	add_to_list(t_linked_list *list, void *new_elt)
{
	if (list->len == list->size)
		double_list_size(list);
	list->elts[list->len] = new_elt;
	list->len++;
}

t_linked_list	*cpy_list(t_linked_list *list)
{
	t_linked_list	*res;

	if (!(res = (t_linked_list*)malloc(sizeof(t_linked_list))))
		malloc_error();
	res->len = 0;
	res->size = list->size;
	if (!(res->elts = (void**)malloc(sizeof(void*) * res->size)))
		malloc_error();
	while (res->len < list->len)
	{
		res->elts[res->len] = list->elts[res->len];
		res->len++;
	}
	return (res);
}

void	free_list(t_linked_list *list)
{
	list->size = 0;
	while (list->size < list->len)
	{
		free(list->elts[list->size]);
		list->size++;
	}
	free(list);
}
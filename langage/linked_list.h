

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include "langage.h"

typedef struct	s_linked_list
{
	void		**elts;
	long		size;
	long		len;
}				t_linked_list;

t_linked_list	*new_list(void);
t_linked_list	*new_list_start_size(long start_size);
void			add_to_list(t_linked_list *list, void *new_elt);
t_linked_list	*cpy_list(t_linked_list *list);
void			free_list(t_linked_list *list);

#endif
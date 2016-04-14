

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include "compiler.h"

typedef struct	s_linked_list
{
	void		**elts;
	int			len;
	int			size;
}				t_linked_list;

t_linked_list	*new_list(void);
void			add_to_list(t_linked_list *list, void *elt);

#endif
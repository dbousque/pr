

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include "language.h"

typedef struct	s_linked_list
{
	void		**elts;
	long		size;
	long		len;
}				t_linked_list;


t_variable		*_new_list_start_size(t_variable *start_size);
t_linked_list	*new_list_start_size(long start_size);

t_variable		*_new_list(void);
t_linked_list	*new_list(void);

void			_add_to_list(t_variable *list, t_variable *new_elt);
void			add_to_list(t_linked_list *list, void *new_elt);

t_variable		*_cpy_list(t_variable *list);
t_linked_list	*cpy_list(t_linked_list *list);

void			_free_list(t_variable *list);
void			free_list(t_linked_list *list);

#endif
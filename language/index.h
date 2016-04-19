

#ifndef INDEX_H
# define INDEX_H

# include "language.h"

t_variable	*_index(t_variable *var, t_variable *ind);
t_variable	*index_linked_list(t_linked_list *list, long ind);
t_variable	*index_string(t_string *string, long ind);

#endif
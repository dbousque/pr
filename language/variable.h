

#ifndef VARIABLE_H
# define VARIABLE_H

# define CHAR 1
# define STRING 2
# define INT 3
# define LONG 4
# define FLOAT 5
# define DOUBLE 6
# define LINKED_LIST 7

typedef struct	s_variable
{
	char		type;
	void		*val;
}				t_variable;

# include "language.h"

t_variable		*new_var(char type);
t_variable		*new_var_from_string(t_string *string);
t_variable		*new_var_from_list(t_linked_list *list);

#endif
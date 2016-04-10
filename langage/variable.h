

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

t_variable		*new_var(char type);

# include "langage.h"

#endif
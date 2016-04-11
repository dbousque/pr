

#ifndef INTEGER_H
# define INTEGER_H

#include "language.h"


t_variable	*_new_int(int n);
t_variable	*_new_int_from_string(t_string *string);
t_variable	*_new_int_from_chars(char *str, long len);

#endif


#ifndef EQUALS_H
# define EQUALS_H

# include "language.h"


t_variable	*_equals(t_variable *var1, t_variable *var2);

char		equals_strings(t_string *str1, t_string *str2);

char		equals_chars(char *str1, char *str2, long len1, long len2);

#endif
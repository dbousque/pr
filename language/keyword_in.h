

#ifndef KEYWORD_IN_H
# define KEYWORD_IN_H

#include "language.h"


t_variable		*_char_in_string(t_variable *c, t_variable *str);
char			char_in_string(char c, char *str, long str_len);

t_variable		*_string_in_linked_list(t_variable *string, t_variable *list);
char			string_in_linked_list(t_string *string, t_linked_list *list);

char			string_in_chartab(t_string *string, char **list, long list_len);

#endif


#ifndef STRING_UTILS_H
# define STRING_UTILS_H

# include "language.h"


void			add_char_to_string(t_string *str1, char c);

void			_concat_strings(t_variable *str1, t_variable *str2);
void			concat_strings(t_string *str1, t_string *str2);

t_variable		*_add_strings(t_variable *str1, t_variable *str2);
t_string		*add_strings(t_string *str1, t_string *str2);

t_variable		*_get_substring(t_variable *str, t_variable *start, t_variable *end);
t_string		*get_substring(t_string *str, long start, long end);

t_variable		*_split_string(t_variable *string, t_variable *to_split);
t_linked_list	*split_string(t_string *string, char to_split);

void			_replace_subpart(t_variable *string, t_variable *start, t_variable *end, t_variable *to_add);
void			replace_subpart(t_string *string, long start, long end, char *to_add, long to_add_len);

#endif
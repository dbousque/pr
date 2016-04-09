

#ifndef STRING_UTILS_H
# define STRING_UTILS_H

# include "langage.h"

t_linked_list	*split_string(t_string *string, char to_split);
void			replace_subpart(t_string *string, long start, long end, char *to_add, long to_add_len);
void			concat_strings(t_string *str1, t_string *str2);
t_string		*add_strings(t_string *str1, t_string *str2);

#endif
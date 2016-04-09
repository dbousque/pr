

#ifndef STRING_H
# define STRING_H

# include "langage.h"

typedef struct	s_string
{
	char		*chars;
	long		len;
	long		size;
	char		freeable;
}				t_string;

t_string		*new_string(void);
t_string		*new_string_of_size(long size);
void			set_string_chars(t_string *string, char *chars, long len);
t_string		*new_void_string(void);

#endif
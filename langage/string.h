

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


t_variable		*_new_void_string(void);
t_string		*new_void_string(void);

t_variable		*_new_string(void);
t_string		*new_string(void);

t_variable		*_new_string_of_size(long size);
t_string		*new_string_of_size(long size);

t_variable		*_new_string_from_chars(char *str, long len);
t_string		*new_string_from_chars(char *str, long len);

void			_set_string_chars(t_string *string, char *chars, long len);
void			set_string_chars(t_string *string, char *chars, long len);

t_variable		*_cpy_string(t_string *string);
t_string		*cpy_string(t_string *string);

#endif
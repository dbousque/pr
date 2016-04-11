

#ifndef PRINT_H
# define PRINT_H

# include "language.h"

void	printn(t_variable *var);
void	print(t_variable *var);
void	print_string(t_string *string);
void	print_string_nl(t_string *string);
void	print_chars(char *str);
void	print_linked_list(t_linked_list *list);
void	print_linked_list_nl(t_linked_list *list);
void	print_char(t_variable *var);
void	print_int(t_variable *var);

#endif
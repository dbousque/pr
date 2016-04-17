

#ifndef FUNCTIONS_TO_C_CODE_H
# define FUNCTIONS_TO_C_CODE_H

# include "compiler.h"

char 			*list_to_string(t_linked_list *list);
t_linked_list	*functions_to_c_code(t_linked_list *functions, t_linked_list *strings);

#endif
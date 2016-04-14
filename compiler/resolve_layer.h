

#ifndef RESOLVE_LAYER_H
# define RESOLVE_LAYER_H

# include "compiler.h"

void			check_indentation(t_linked_list *abstracted_layer);
void			check_parentheses_and_brackets_close(t_linked_list *abstracted_layer);
t_linked_list	*resolve_layer(t_linked_list *abstracted_layer, t_linked_list *splitted_strings);

#endif
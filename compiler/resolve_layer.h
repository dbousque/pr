

#ifndef RESOLVE_LAYER_H
# define RESOLVE_LAYER_H

# include "compiler.h"

void			print_resolved_layer(t_linked_list *layer);
char			string_in_list(char *string, t_linked_list *list);
t_linked_list	*resolve_layer(t_linked_list *abstracted_layer, t_linked_list *splitted_strings);

#endif
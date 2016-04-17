

#ifndef COMPILER_H
# define COMPILER_H

typedef struct	s_linked_list t_linked_list;
typedef struct	s_tree t_tree;

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

# include "../utils/utils.h"
# include "read_source.h"
# include "errors.h"
# include "linked_list.h"
# include "parser.h"
# include "abstraction_layer.h"
# include "resolve_layer.h"
# include "builtin_functions.h"
# include "builtin_keywords.h"
# include "cut_into_functions.h"
# include "functions_to_c_code.h"
# include "resolve_part.h"
//# include "syntax_tree.h"

void      check_indentation(t_linked_list *abstracted_layer);
void      check_parentheses_and_brackets_close(t_linked_list *abstracted_layer);

#endif
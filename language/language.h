

#ifndef LANGAGE_H
# define LANGAGE_H

typedef struct	s_linked_list t_linked_list;
typedef struct	s_string t_string;

# define NEW_STRING_EXTRA_CHARS 8
# define LINKED_LIST_START_SIZE 8

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>

# include "../utils/utils.h"
# include "variable.h"
# include "string.h"
# include "string_utils.h"
# include "linked_list.h"
# include "char.h"
# include "integer.h"
# include "errors.h"
# include "print.h"
# include "equals.h"
# include "keyword_in.h"
# include "args_from_c_args.h"
# include "index.h"
# include "add.h"
# include "multiply.h"
# include "divide.h"
# include "minus.h"
# include "is_less.h"
# include "plus_equal.h"

#endif
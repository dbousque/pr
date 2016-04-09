

#ifndef LANGAGE_H
# define LANGAGE_H

# define NEW_STRING_EXTRA_CHARS 8
# define LINKED_LIST_START_SIZE 8

typedef struct	s_string t_string;
typedef struct	s_linked_list t_linked_list;

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>

# include "string.h"
# include "string_utils.h"
# include "linked_list.h"
# include "errors.h"
# include "print.h"

#endif


#ifndef COMPILER_H
# define COMPILER_H

typedef struct	s_linked_list t_linked_list;

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

#endif
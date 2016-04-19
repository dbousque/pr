

#ifndef TREE_H
# define TREE_H

# define END_NODE 0
# define END_NODE_INT 1
# define INDEX 2
# define ADD 3
# define MINUS 4
# define MULTIPL 5
# define DIVID 6
# define FUNCTION_NODE 7
# define ARGUMENTS 8
# define ASSIGNEMENT 9
# define RETU 10

#include "../../utils/utils.h"

typedef struct		s_node
{
	char			action;
	struct s_node	*left;
	struct s_node	*right;
	char			*repr;
}					t_node;

t_node	*new_node(char action, t_node *left, t_node *right, char *repr);

#endif
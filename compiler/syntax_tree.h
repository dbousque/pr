

#ifndef SYNTAX_TREE_H
# define SYNTAX_TREE_H

/*# include "compiler.h"

# define TYPE_FUNCTION 1
# define TYPE_VARIABLE 2
# define TYPE_CONDITIONS_BLOCK 3
# define TYPE_CONDITION_BLOCK 4

typedef struct		s_tree
{
	t_linked_list	*functions;
}					t_tree;

typedef struct		s_tree_elt
{
	char			type;
	void			*elt;
}					t_tree_elt;

typedef struct		s_function
{
	t_linked_list	*arguments;
	char			returns;
	char			*name;
	t_linked_list	*instructions;
}					t_function;

typedef struct		s_variable
{
	char			*name;
}					t_variable;

typedef struct		s_conditions_block
{
	t_linked_list	*condition_blocks;
}					t_conditions_block;

typedef struct		s_condition_block
{
	t_condition		*condition;
	t_linked_list	*instructions;
}					t_condition_block;

typedef struct		s_condition
{

}					t_condition;

typedef struct		s_assignment
{
	t_variable		*variable;
	t_expression	*expression;
}					t_assignment;*/

/*typedef struct		s_expression
{
	// made of t_tree_elt
	t_linked_list	*sub_expressions;
}					t_expression;*/

#endif
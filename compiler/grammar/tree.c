

#include "tree.h"

t_node	*new_node(char action, t_node *left, t_node *right, char *repr)
{
	t_node	*node;

	if (!(node = (t_node*)malloc(sizeof(t_node))))
	{
		exit(1);
	}
	node->action = action;
	node->left = left;
	node->right = right;
	if (!left && !right)
		node->repr = ft_strdup(repr);
	return (node);
}
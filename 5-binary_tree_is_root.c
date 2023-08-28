#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if a given node is a root
 * @node: the node to be checked
 * Return: 0, 1
*/
int binary_tree_is_root(const binary_tree_t *node)
{
	return (node && node->parent == NULL);
}

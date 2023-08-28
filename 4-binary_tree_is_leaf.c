#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: the node to be checked
 * Return: 0 or 1.
*/
int binary_tree_is_leaf(const binary_tree_t *node)
{
	return (node && node->left == NULL && node->right == NULL);
}

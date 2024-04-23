#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: the address of the node
 * Return: address of the uncle node
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grand_parent;

	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);
	grand_parent = node->parent->parent;
	if (grand_parent->left == node->parent)
		return (grand_parent->right);
	else
		return (grand_parent->left);
}

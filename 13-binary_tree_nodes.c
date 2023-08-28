#include "binary_trees.h"

/**
 * binary_tree_nodes - measures the number of non-leaves in a binary tree
 * @tree: the address of the root node
 * Return: the number of a non-leaves nodes
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree == NULL)
		return (0);
	nodes += binary_tree_nodes(tree->left);
	nodes += binary_tree_nodes(tree->right);
	return ((tree->left || tree->right) ? nodes + 1 : nodes);
}

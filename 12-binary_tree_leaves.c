#include "binary_trees.h"

/**
 * binary_tree_leaves - measures the number of leaves in a binary tree
 * @tree: the address of the root node
 * Return: the number of a leaves
*/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree == NULL)
		return (0);
	leaves += binary_tree_leaves(tree->left);
	leaves += binary_tree_leaves(tree->right);
	return ((!tree->left && !tree->right) ? leaves + 1 : leaves);
}

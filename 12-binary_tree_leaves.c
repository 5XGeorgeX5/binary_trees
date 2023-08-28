#include "binary_trees.h"

/**
 * binary_tree_leaves - measures the number of leaves in a binary tree
 * @tree: the address of the root node
 * Return: the number of a leaves
*/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t left, right, leaves;

	if (tree == NULL)
		return (0);
	left = binary_tree_leaves(tree->left);
	right = binary_tree_leaves(tree->right);
	leaves = left + right;
	return ((!left && !right) ? leaves + 1 : leaves);
}

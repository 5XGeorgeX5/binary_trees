#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: pointer to the root node
 * @value: the value to be search for
 * Return: the address of the node containing the vale
*/
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);
	if (value == tree->n)
		return ((bst_t *)tree);
	if (value > tree->n)
		return (bst_search(tree->right, value));
	if (value < tree->n)
		return (bst_search(tree->left, value));
	return (NULL);
}

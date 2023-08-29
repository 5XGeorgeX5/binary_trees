#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: the address of the root node
 * Return: pointer to the new root node of the tree once rotated
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new;

	if (tree == NULL || tree->right == NULL)
		return (NULL);
	new = tree->right;
	tree->right = new->left;
	new->left = tree;
	tree->parent = new;
	new->parent = NULL;
	return (new);
}

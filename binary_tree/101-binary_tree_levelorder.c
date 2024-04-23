#include "binary_trees.h"

/**
 * bi_height - Measures the height of a binary tree
 * @tree: Pointer to the node to measures the height
 * Return: The height of the tree starting at @node
 */
size_t bi_height(const binary_tree_t *tree)
{
	size_t left = 1;
	size_t right = 1;

	if (tree == NULL)
		return (0);
	left += bi_height(tree->left);
	right += bi_height(tree->right);
	return (left > right ? left : right);
}

/**
 * do_func - call the func
 * @tree: The address of the toot node
 * @level: the height of the tree
 * @func: the func to be called
*/
void do_func(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (level == 0)
		func(tree->n);
	else
	{
		do_func(tree->left, level - 1, func);
		do_func(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - goes through a binary tree using level-order
 * @tree: the address of the root node
 * @func: is a pointer to a function to call for each node
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height = bi_height(tree);
	int i;

	if (tree == NULL || (*func) == NULL)
		return;
	for (i = 0; i < height; i++)
		do_func(tree, i, func);
}

#include "binary_trees.h"

/**
 * bi_height - Measures the height of a binary tree
 * @tree: Pointer to the node to measures the height
 * Return: The height of the tree starting at @node
 */
size_t bi_height(const binary_tree_t *tree)
{
	size_t left;
	size_t right;

	if (tree == NULL)
		return (-1);
	left = tree->left ? 1 + bi_height(tree->left) : 0;
	right = tree->right ? 1 + bi_height(tree->right) : 0;
	return (left > right ? left : right);
}

/**
 * binary_tree_balance - measures the balance factor in a binary tree
 * @tree: the address of the root node
 * Return: the balance factor
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (bi_height(tree->left) - bi_height(tree->right));
}

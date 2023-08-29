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
 * bi_full - checks if a binary tree is full
 * @tree: Pointer to the node to measures the height
 * Return: 0, 1
 */
int bi_full(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);
	if (tree->left && tree->right)
	{
		left = bi_full(tree->left);
		right = bi_full(tree->right);
		return (left && right);
	}
	return (tree->left == NULL && tree->right == NULL);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: the address of the root node
 * Return: 0, 1
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (!(bi_height(tree->left) - bi_height(tree->right)) && bi_full(tree));
}

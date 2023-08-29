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
		return (0);
	left = tree->left ? 1 + bi_height(tree->left) : 0;
	right = tree->right ? 1 + bi_height(tree->right) : 0;
	return (left > right ? left : right);
}

/**
 * bi_size - measures the size of a binary tree
 * @tree: the address of the root node
 * Return: the size of the binary tree
*/
size_t bi_size(const binary_tree_t *tree)
{
	size_t size = 1;

	if (tree == NULL)
		return (0);
	size += bi_size(tree->left);
	size += bi_size(tree->right);
	return (size);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: the address of the root node
 * Return: 0, 1
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t num = 2;
	size_t hight = bi_height(tree);

	while (hight--)
		num *= 2;

	return (num - 1 == bi_size(tree));
}

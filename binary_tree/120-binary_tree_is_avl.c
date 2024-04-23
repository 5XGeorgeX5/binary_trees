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
 * bi_max - return the max value
 * @tree: the node
 * Return: the max value
*/
int bi_max(const binary_tree_t *tree)
{
	int max_left, max_right, result = 0;

	if (tree == NULL)
		return (0);
	max_left = bi_max(tree->left);
	max_right = bi_max(tree->right);
	if (max_left > max_right)
		result = max_left;
	else
		result = max_right;
	if (result < tree->n)
		result = tree->n;
	return (result);
}

/**
 * bi_min - return the min value
 * @tree: the node
 * Return: the min value
*/
int bi_min(const binary_tree_t *tree)
{
	int min_left, min_right, result = 0;

	if (tree == NULL)
		return (2147483647);
	min_left = bi_min(tree->left);
	min_right = bi_min(tree->right);
	if (min_left < min_right)
		result = min_left;
	else
		result = min_right;
	if (result > tree->n)
		result = tree->n;
	return (result);
}

/**
 * is_avl - checks if a binary tree is a valid AVL tree
 * @tree: the address of the root node
 * Return: 0, 1
*/
int is_avl(const binary_tree_t *tree)
{
	int balance;

	if (tree == NULL)
		return (1);
	balance = bi_height(tree->left) - bi_height(tree->right);
	if (balance > 1 || balance < -1)
		return (0);
	if (tree->left && bi_max(tree->left) >= tree->n)
		return (0);
	if (tree->right && bi_min(tree->right) <= tree->n)
		return (0);
	return (is_avl(tree->left) && is_avl(tree->right));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL tree
 * @tree: the address of the root node
 * Return: 0, 1
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_avl(tree));
}

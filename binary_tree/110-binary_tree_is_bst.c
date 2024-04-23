#include "binary_trees.h"

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
 * is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: the address of the root node
 * Return: 0, 1
*/
int is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);
	if (tree->left && bi_max(tree->left) >= tree->n)
		return (0);
	if (tree->right && bi_min(tree->right) <= tree->n)
		return (0);
	return (is_bst(tree->left) &&
			is_bst(tree->right));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: the address of the root node
 * Return: 0, 1
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst(tree));
}

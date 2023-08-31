#include "binary_trees.h"

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
 * is_complete - checks if a binary tree is complete
 * @tree: the address of the root node
 * @index: the index in the corresponding array
 * @size: the size of the tree
 * Return: 0, 1
*/
int is_complete(const binary_tree_t *tree, size_t index, size_t size)
{
	if (tree == NULL)
		return (1);
	if (index >= size)
		return (0);
	return (is_complete(tree->left, 2 * index + 1, size) &&
		is_complete(tree->right, 2 * index + 2, size));
}

/**
 * check - check  if a tree is heap
 * @tree: the address of the root node
 * Return: 0, 1
*/
int check(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);
	if (tree->n > tree->parent->n)
		return (0);
	return (check(tree->left) && check(tree->right));
}

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: the address of the root node
 * Return: 0, 1
*/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (is_complete(tree, 0, bi_size(tree)) == 0)
		return (0);
	return (check(tree->left) && check(tree->right));
}

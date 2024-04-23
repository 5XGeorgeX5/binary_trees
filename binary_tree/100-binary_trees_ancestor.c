#include "binary_trees.h"

/**
 * bi_depth - measures the depth of a node in a binary tree
 * @tree: the address of the root node
 * Return: the depth of a node
*/
size_t bi_depth(const binary_tree_t *tree)
{
	size_t depth;

	if (tree == NULL)
		return (0);
	depth = tree->parent ? 1 + bi_depth(tree->parent) : 0;
	return (depth);
}

/**
 * binary_trees_ancestor - finds the ancestor of a two node
 * @first: the address of the first node
 * @second: the address of the second node
 * Return: address of the ancestor
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									const binary_tree_t *second)
{
	size_t d1 = bi_depth(first), d2 = bi_depth(second);

	if (d1 > d2)
	{
		d1 -= d2;
		while (d1--)
			first = first->parent;
	}
	else if (d2 > d1)
	{
		d2 -= d1;
		while (d2--)
			second = second->parent;
	}
	while (first && second && first != second)
	{
		first = first->parent;
		second = second->parent;
	}
	if (first && second)
		return ((binary_tree_t *)first);
	return (NULL);
}

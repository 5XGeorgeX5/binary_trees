#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: the address of the parent node
 * @value: the value of the left node
 * Return: the address to the left node
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left;

	if (parent == NULL)
		return (NULL);
	left = binary_tree_node(parent, value);
	if (left == NULL)
		return (NULL);
	left->left = parent->left;
	parent->left = left;
	if (left->left != NULL)
		left->left->parent = left;
	return (left);
}

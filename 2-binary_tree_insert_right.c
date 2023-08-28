#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: the address of the parent node
 * @value: the value of the right node
 * Return: the address to the right node
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right;

	if (parent == NULL)
		return (NULL);
	right = binary_tree_node(parent, value);
	if (right == NULL)
		return (NULL);
	right->right = parent->right;
	parent->right = right;
	if (right->right != NULL)
		right->right->parent = right;
	return (right);
}

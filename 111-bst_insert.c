#include "binary_trees.h"

/**
 * bst_insert - insert a new node into a bst
 * @tree: the address of the root node
 * @value: the function to apply
 * Return: the address of the new node
*/
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *it = *tree;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	while (1)
	{
		if (value < it->n)
		{
			if (it->left)
				it = it->left;
			else
			{
				it->left = binary_tree_node(it, value);
				return (it->left);
			}
		}
		else if (value > it->n)
		{
			if (it->right)
				it = it->right;
			else
			{
				it->right = binary_tree_node(it, value);
				return (it->right);
			}
		}
		else
			break;
	}
	return (NULL);
}

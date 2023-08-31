#include "binary_trees.h"

/**
 * bst_s - searches for a value in a Binary Search Tree
 * @tree: pointer to the root node
 * @value: the value to be search for
 * Return: the address of the node containing the vale
*/
bst_t *bst_s(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);
	if (value == tree->n)
		return ((bst_t *)tree);
	if (value > tree->n)
		return (bst_s(tree->right, value));
	if (value < tree->n)
		return (bst_s(tree->left, value));
	return (NULL);
}

/**
 * check - return the new root
 * @root: the root node
 * @node: the node to be removed
 * @d1: node child
 * Return: the address of the new root
*/
bst_t *check(bst_t *root, bst_t *node, bst_t *d1)
{
	if (d1 == NULL)
	{
		if (node->parent)
		{
			if (node->parent->left == node)
				node->parent->left = NULL;
			else
				node->parent->right = NULL;
		}
		if (node == root)
			free(node);
		else
		{
			free(node);
			return (root);
		}
	}
	else
	{
		d1->parent = node->parent;
		if (node->parent)
		{
			if (node->parent->left == node)
				node->parent->left = d1;
			else
				node->parent->right = d1;
		}
		if (node == root)
		{
			free(node);
			return (d1);
		}
		else
		{
			free(node);
			return (root);
		}
	}
	return (NULL);
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node
 * @value: the value to be removed from the tree
 * Return: the address of the new root node
*/
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node, *new_root;

	if (root == NULL)
		return (NULL);
	node = bst_s(root, value);
	if (node == NULL)
		return (NULL);
	if (node->left == NULL)
		return (check(root, node, node->right));
	if (node->right == NULL)
		return (check(root, node, node->left));
	new_root = node->right;
	if (new_root->left)
	{
		while (new_root->left)
			new_root = new_root->left;
		new_root->parent->left = NULL;
	}
	else
	{
		if (new_root->right)
			new_root->right->parent = node;
		node->right = new_root->right;
	}
	node->n = new_root->n;
	free(new_root);
	return (root);
}

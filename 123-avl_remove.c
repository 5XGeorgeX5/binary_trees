#include "binary_trees.h"

/**
 * avl_search - searches for a value in a Binary Search Tree
 * @tree: pointer to the root node
 * @value: the value to be search for
 * Return: the address of the node containing the vale
*/
avl_t *avl_search(const avl_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);
	if (value == tree->n)
		return ((avl_t *)tree);
	if (value > tree->n)
		return (avl_search(tree->right, value));
	if (value < tree->n)
		return (avl_search(tree->left, value));
	return (NULL);
}

/**
 * check - return the new root
 * @node: the node to be removed
 * @d1: node child
 * Return: the address of the new root
*/
avl_t *check(avl_t *node, avl_t *d1)
{
	avl_t *parent = node->parent;

	if (d1 == NULL)
	{
		if (parent)
		{
			if (parent->left == node)
				parent->left = NULL;
			else
				parent->right = NULL;
		}
	}
	else
	{
		d1->parent = parent;
		if (parent)
		{
			if (parent->left == node)
				parent->left = d1;
			else
				parent->right = d1;
		}
	}
	free(node);
	return (parent);
}

/**
 * avl_balance - keeps the AVL tree balanced
 * @node: the new inserted node
 * Return: the root
*/
avl_t *avl_balance(avl_t *node)
{
	int balance;

	while (1)
	{
		balance = binary_tree_balance(node);
		if (balance > 1)
			node = binary_tree_rotate_right(node);
		else if (balance < -1)
			node = binary_tree_rotate_left(node);
		if (node->parent)
			node = node->parent;
		else
			break;
	}
	return (node);
}
/**
 * avl_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node
 * @value: the value to be removed from the tree
 * Return: the address of the new root node
*/
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *node, *new_root, *parent;

	if (root == NULL)
		return (NULL);
	node = avl_search(root, value);
	if (node == NULL)
		return (NULL);
	if (node->left == NULL)
		parent = check(node, node->right);
	else if (node->right == NULL)
		parent = check(node, node->left);
	else
	{
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
		parent = new_root->parent;
		free(new_root);
	}
	if (parent)
		root = avl_balance(parent);
	return (root);
}

#include "binary_trees.h"

/**
 * bi_height - Measures the height of a binary tree
 * @tree: Pointer to the node to measures the height
 * Return: The height of the tree starting at @node
 */
size_t bi_height(const heap_t *tree)
{
	size_t left = 1;
	size_t right = 1;

	if (tree == NULL)
		return (0);
	left += bi_height(tree->left);
	right += bi_height(tree->right);
	return (left > right ? left : right);
}

/**
 * heapify - makes the max binary tree
 * @node: the  node to be inserted
 */
void heapify(heap_t *node)
{
	heap_t *max = node;
	int tmp;

	if (node->left && max->n < node->left->n)
		max = node->left;

	if (node->right && max->n < node->right->n)
		max = node->right;

	if (max != node)
	{
		tmp = max->n;
		max->n = node->n;
		node->n = tmp;
		heapify(max);
	}
}

/**
 * do_insert - call the func
 * @tree: The address of the toot node
 * @level: the level of the tree
 * @node: the node to be inserted
 * @done: 0, 1
 * Return: 0, 1
*/
int do_insert(heap_t *tree, heap_t *node, int level, int done)
{
	if (done)
		return (1);
	if (level == 0)
		return (0);
	if (level == 1)
	{
		if (tree->left == NULL)
		{
			tree->left = node;
			node->parent = tree;
			return (1);
		}
		if (tree->right == NULL)
		{
			tree->right = node;
			node->parent = tree;
			return (1);
		}
	}
	done = do_insert(tree->left, node, level - 1, done);
	done = do_insert(tree->right, node, level - 1, done);
	return (done);
}

/**
 * do_heapify - insert the node into heap
 * @tree: the root node
 * @level: the level of the tree
*/
void do_heapify(heap_t *tree, int level)
{
	if (tree == NULL)
		return;
	if (level == 0)
		heapify(tree);
	else
	{
		do_heapify(tree->left, level - 1);
		do_heapify(tree->right, level - 1);
	}
}

/**
 * heap_insert - insert a new node into a avl
 * @root: the address of the root node
 * @value: the function to apply
 * Return: the address of the new node
*/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node, *it;
	int height = bi_height(*root) - 1, i;

	if (root == NULL)
		return (NULL);
	node = binary_tree_node(NULL, value);
	if (*root == NULL)
	{
		*root = node;
		return (*root);
	}
	if (!do_insert(*root, node, height, 0))
	{
		it = *root;
		while (it->left)
			it = it->left;
		it->left = node;
		node->parent = it;
	}
	for (i = height; i >= 0; i--)
		do_heapify(*root, i);
	while (node->n != value)
		node = node->parent;
	return (node);
}

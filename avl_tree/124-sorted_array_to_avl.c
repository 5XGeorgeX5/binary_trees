#include "binary_trees.h"

/**
 * to_avl - convert a sorted array into avl
 * @parent: the node parent
 * @array: the array
 * @start: the start of the array
 * @end: the end of the array
 * Return: the address of the root node
*/
avl_t *to_avl(avl_t *parent, int *array, int start, int end)
{
	avl_t *tree;
	int mid;

	if (start > end)
		return (NULL);
	mid = (start + end) / 2;
	tree = binary_tree_node(parent, array[mid]);
	if (tree == NULL)
		return (NULL);
	tree->left = to_avl(tree, array, start, mid - 1);
	tree->right = to_avl(tree, array, mid + 1, end);
	return (tree);
}
/**
 * sorted_array_to_avl - builds a AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: the address of the root node
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array)
		return (NULL);
	return (to_avl(NULL, array, 0, size - 1));
}

#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
	bst_t *tree;
	int array[] = {
		10, 9, 8, 7, 11, 12, 13
	};
	size_t n = sizeof(array) / sizeof(array[0]);

	tree = array_to_bst(array, n);
	if (!tree)
		return (1);
	binary_tree_print(tree);

	tree = bst_remove(tree, 10);
	printf("Removed 10...\n");
	binary_tree_print(tree);

	tree = bst_remove(tree, 7);
	printf("Removed 7...\n");
	binary_tree_print(tree);

	tree = bst_remove(tree, 9);
	printf("Removed 9...\n");
	binary_tree_print(tree);
	binary_tree_delete(tree);
	return (0);
}
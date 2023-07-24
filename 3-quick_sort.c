#include "sort.h"

void int_swp(int *i, int *j);
int parti_Lomuto(int *array, size_t size, int lft, int rght);
void sort_Lomuto(int *array, size_t size, int lft, int rght);
void quick_sort(int *array, size_t size);

/**
 * quick_sort -	sorts an array of integers in an ascending
 *			order using the quicksort algorithm and prints it
 * @array: integers
 * @size: array size
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sort_Lomuto(array, size, 0, size - 1);
}
/**
 * sort_Lomuto - implements the Quicksort algorithm using recursion
 * @array: integers to sort
 * @size: array size
 * @lft: starting index of the array partition to order
 * @rght: ending index of the array partition to order
 *
 * Return: void
 */
void sort_Lomuto(int *array, size_t size, int lft, int rght)
{
	int parti;

	if (rght - lft > 0)
	{
		parti = parti_Lomuto(array, size, lft, rght);
		sort_Lomuto(array, size, lft, parti - 1);
		sort_Lomuto(array, size, parti + 1, rght);
	}
}
/**
 * parti_Lomuto -	orders the subset of an array of integers
 *			according to the Lomuto partition scheme, last element as a pivot
 * @array: integers
 * @size: array size
 * @lft: starting index of the subset to order
 * @rght: ending index of the subset to order
 *
 * Return: the final partition index
 */
int parti_Lomuto(int *array, size_t size, int lft, int rght)
{
	int *pivo, above, below;

	pivo = array + rght;

	for (above = below = lft; below < rght; below++)
	{
		if (array[below] < *pivo)
		{
			if (above < below)
			{
				int_swp(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}
	if (array[above] > *pivo)
	{
		int_swp(array + above, pivo);
		print_array(array, size);
	}
	return (above);
}
/**
 * int_swp - swaps two integers in an array
 * @i: 1st integer
 * @j: 2nd integer
 */
void int_swp(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

#include "sort.h"

void int_swp(int *i, int *j);

/**
 * selection_sort -	sorts an array of integers in an ascending order using
 *			the Selection sort algorithm and prints it
 * @array: integers
 * @size: array size
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	int *mini;
	size_t i, j;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		mini = array + i;
		for (j = i + 1; j < size; j++)
			mini = (array[j] < *mini) ? (array + j) : mini;
		if ((array + i) != mini)
		{
			int_swp(array + i, mini);
			print_array(array, size);
		}
	}
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

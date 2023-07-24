#include "sort.h"

void int_swp(int *i, int *j);

/**
 * shell_sort -		sorts an array of integers in an ascending order using
 *			the Shell sort algorithm
 * @array: integers
 * @size: array size
 * Description: implements the Knuth sequence variatiaon
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t gap_sq, i, j;

	if (array == NULL || size < 2)
		return;
	for (gap_sq = 1; gap_sq < (size / 3);)
		gap_sq = gap_sq * 3 + 1;

	for (; gap_sq >= 1; gap_sq /= 3)
	{
		for (i = gap_sq; i < size; i++)
		{
			j = i;
			while (j >= gap_sq && array[j - gap_sq] > array[j])
			{
				int_swp(array + j, array + (j - gap_sq));
				j -= gap_sq;
			}
		}
		print_array(array, size);
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

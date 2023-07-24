#include "sort.h"

void int_swp(int *i, int *j);

/**
 * bubble_sort -	sorts an array of integers in an ascending order using
 *			the Bubble sort algorithm and prints it
 * @array: integers to sort
 * @size: array size
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, ln = size;
	bool bbl = false;

	if (array == NULL || size < 2)
		return;
	while (bbl == false)
	{
		bbl = true;
		for (i = 0; i < ln - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				int_swp(array + i, array + i + 1);
				print_array(array, size);
				bbl = false;
			}
		}
		ln--;
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

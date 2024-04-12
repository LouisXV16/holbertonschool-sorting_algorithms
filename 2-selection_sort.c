#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array to be sorted
 * @size: size of the array
*/

void selection_sort(int *array, size_t size)
{
	size_t index, index2, min;
	int tempo;

	if (array == NULL || size < 2)
		return;

	/* Loop through the array multiple times*/
	for (index = 0; index < size - 1; index++)
	{
		/* Suppose the first element is the minimum */
		min = index;

		/* Find the minimum element in unsorted array */
		for (index2 = index + 1; index2 < size; index2++)
		{
			/*if the element is less, then it is the new minimum*/
			if (array[index2] < array[min])
				min = index2;
		}
		/* Swap the found minimum element with the first element */
		if (min != index)
		{
			tempo = array[index];
			array[index] = array[min];
			array[min] = tempo;

			print_array(array, size);
		}
	}
}

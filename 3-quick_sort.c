#include "sort.h"

/**
 * Swap two elements in the array.
 * @a: Pointer to the first element.
 * @b: Pointer to the second element.
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Lomuto partition scheme for Quick sort.
 * @array: The array to be sorted.
 * @low: Starting index of the sub-array to be partitioned.
 * @high: Ending index of the sub-array to be partitioned.
 * @size: The total size of the array for printing.
 * Returns: The partitioning index.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
            if (i != j)
                print_array(array, size);
        }
    }
    swap(&array[i + 1], &array[high]);
    if (high != (i + 1))
        print_array(array, size);
    return (i + 1);
}

/**
 * Quick sort algorithm using Lomuto partition scheme.
 * @array: The array to be sorted.
 * @low: Starting index for the sorting algorithm.
 * @high: Ending index for the sorting algorithm.
 * @size: The total size of the array for printing.
 */
void quick_sort_rec(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pi = lomuto_partition(array, low, high, size);
        quick_sort_rec(array, low, pi - 1, size);
        quick_sort_rec(array, pi + 1, high, size);
    }
}

/**
 * Quick sort function interface.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;
    quick_sort_rec(array, 0, size - 1, size);
}

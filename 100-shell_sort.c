#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array.
 * @a: Pointer to the first integer to swap.
 * @b: Pointer to the second integer to swap.
 *
 * Description: This function swaps two integers in an array.
 */
void swap_ints(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * shell_sort - Sorts an array of integers in ascending order using shell sort.
 * @array: Pointer to the array of integers to be sorted.
 * @size: Size of the array.
 *
 * Description: This function sorts the given array in ascending order using the
 * shell sort algorithm. It divides the array into subarrays based on a gap sequence
 * and performs insertion sort on each subarray. The gap sequence used is the Knuth
 * interval sequence. Prints the array after each swap.
 */
void shell_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    size_t gap, i, j;

    /* Initialize the gap sequence */
    for (gap = 1; gap < size / 3;)
        gap = gap * 3 + 1;

    /* Perform shell sort */
    for (; gap >= 1; gap /= 3)
    {
        for (i = gap; i < size; i++)
        {
            /*  Perform insertion sort within each subarray */
            for (j = i; j >= gap && array[j - gap] > array[j]; j -= gap)
            {
                swap_ints(&array[j], &array[j - gap]);
            }
        }
        print_array(array, size);
    }
}

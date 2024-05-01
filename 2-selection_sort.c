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
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: Pointer to the array of integers to be sorted.
 * @size: Size of the array.
 *
 * Description: This function sorts the given array in ascending order using
 * the selection sort algorithm. It repeatedly finds the minimum element from
 * the unsorted part of the array and swaps it with the first unsorted element.
 * Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    size_t i, j, min_index;

    for (i = 0; i < size - 1; i++)
    {
        min_index = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_index])
                min_index = j;
        }

        if (min_index != i)
        {
            swap_ints(&array[i], &array[min_index]);
            print_array(array, size);
        }
    }
}

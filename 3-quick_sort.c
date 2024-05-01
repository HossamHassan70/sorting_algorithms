#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
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
 * lomuto_partition - Partition a subset of an array using the Lomuto scheme.
 * @array: Pointer to the array to partition.
 * @size: Size of the array.
 * @left: Starting index of the subset to partition.
 * @right: Ending index of the subset to partition.
 *
 * Return: The final partition index.
 *
 * Description: This function partitions a subset of an array using the Lomuto
 * scheme, with the last element as the pivot. It rearranges the elements such
 * that all elements less than the pivot are placed before it, and all elements
 * greater than the pivot are placed after it. Prints the array after each swap.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
    int pivot = array[right];
    int i = left - 1;

    for (int j = left; j <= right - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap_ints(&array[i], &array[j]);
            print_array(array, size);
        }
    }
    swap_ints(&array[i + 1], &array[right]);
    print_array(array, size);
    return (i + 1);
}

/**
 * lomuto_sort - Implement the quicksort algorithm using the Lomuto scheme.
 * @array: Pointer to the array to sort.
 * @size: Size of the array.
 * @left: Starting index of the array partition to sort.
 * @right: Ending index of the array partition to sort.
 *
 * Description: This function recursively sorts a partition of the array using
 * the quicksort algorithm with the Lomuto partition scheme. It divides the array
 * into two partitions, sorts each partition separately, and then combines them.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
    if (left < right)
    {
        int pivot_index = lomuto_partition(array, size, left, right);
        lomuto_sort(array, size, left, pivot_index - 1);
        lomuto_sort(array, size, pivot_index + 1, right);
    }
}

/**
 * quick_sort - Sort an array of integers in ascending order using quicksort.
 * @array: Pointer to the array to sort.
 * @size: Size of the array.
 *
 * Description: This function sorts an array of integers in ascending order using
 * the quicksort algorithm. It uses the Lomuto partition scheme for partitioning
 * the array. Prints the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    lomuto_sort(array, size, 0, size - 1);
}

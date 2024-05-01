#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * hoare_partition - Partition the array using the Hoare scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the partition.
 * @right: The ending index of the partition.
 *
 * Return: The partition index.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
    int pivot = array[right];
    int i = left - 1;
    int j = right + 1;

    while (1)
    {
        do
        {
            i++;
        } while (array[i] < pivot);

        do
        {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap_ints(&array[i], &array[j]);
        print_array(array, size);
    }
}

/**
 * hoare_sort - Sort the array using the Hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the partition.
 * @right: The ending index of the partition.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
    if (left < right)
    {
        int partition = hoare_partition(array, size, left, right);
        hoare_sort(array, size, left, partition);
        hoare_sort(array, size, partition + 1, right);
    }
}

/**
 * quick_sort_hoare - Sort the array using the quicksort algorithm with Hoare partition.
 * @array: The array of integers.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    hoare_sort(array, size, 0, size - 1);
}

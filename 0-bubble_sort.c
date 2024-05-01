#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: Pointer to the first integer to swap.
 * @b: Pointer to the second integer to swap.
 *
 * Return: Void.
 */
void swap_ints(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order using bubble sort.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 *
 * Description: This function sorts the given array in ascending order using the
 * bubble sort algorithm. It iterates through the array multiple times, comparing
 * adjacent elements and swapping them if they are in the wrong order. The process
 * repeats until no swaps are performed in a pass, indicating that the array is sorted.
 * The function also prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, len = size;
    bool swapped = false;

    if (array == NULL || size < 2)
        return;

    do
    {
        swapped = false;
        for (i = 0; i < len - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                swap_ints(&array[i], &array[i + 1]);
                print_array(array, size);
                swapped = true;
            }
        }
        len--;
    } while (swapped);
}

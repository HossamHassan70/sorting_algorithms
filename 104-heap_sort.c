#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * heapify - Turn a subtree into a max heap.
 * @array: The array to be sorted.
 * @size: Size of the array/subtree.
 * @root: The root index of the subtree.
 */
void heapify(int *array, size_t size, size_t root)
{
    size_t largest = root;
    size_t left = 2 * root + 1;
    size_t right = 2 * root + 2;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != root)
    {
        swap_ints(&array[root], &array[largest]);
        heapify(array, size, largest);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using heap sort.
 * @array: The array to be sorted.
 * @size: Size of the array.
 *
 * Description: Implements the bottom-up heap sort algorithm.
 * Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    /* Build heap */ 
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);

    /* Extract elements Heap sort */ 
    for (int i = size - 1; i > 0; i--)
    {
        swap_ints(&array[0], &array[i]);
        print_array(array, size);
        heapify(array, i, 0);
    }
}

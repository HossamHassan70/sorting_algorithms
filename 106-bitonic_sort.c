#include "sort.h"

void bitonic_merge(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort_recursive(int *array, size_t size, size_t start, size_t seq, char flow);

/**
 * bitonic_merge - Merge two bitonic sequences in a given array.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in array to merge.
 * @seq: The size of the sequence to merge.
 * @flow: The direction of the bitonic sequence.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, char flow)
{
    size_t i, jump = seq / 2;

    if (seq > 1)
    {
        for (i = start; i < start + jump; i++)
        {
            if ((flow == UP && array[i] > array[i + jump]) ||
                (flow == DOWN && array[i] < array[i + jump]))
                swap_ints(array + i, array + i + jump);
        }
    }
}

/**
 * bitonic_sort_recursive - Sort a bitonic sequence recursively.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in array to sort.
 * @seq: The size of the sequence to sort.
 * @flow: The direction of the bitonic sequence.
 */
void bitonic_sort_recursive(int *array, size_t size, size_t start, size_t seq, char flow)
{
    size_t jump = seq / 2;

    if (seq > 1)
    {
        bitonic_sort_recursive(array, size, start, jump, UP);
        bitonic_sort_recursive(array, size, start + jump, jump, DOWN);
        bitonic_merge(array, size, start, seq, flow);
    }
}

/**
 * bitonic_sort - Sort an array of integers in ascending order
 *                using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: This function sorts the array using the bitonic sort algorithm.
 * It divides the array into bitonic sequences recursively and merges them.
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_sort_recursive(array, size, 0, size, UP);
}

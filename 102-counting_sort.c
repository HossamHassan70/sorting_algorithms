#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 *
 * Description: This function iterates through the given array to find the maximum
 * integer value.
 */
int get_max(int *array, size_t size)
{
    int max = array[0];

    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    return max;
}

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                 the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: This function sorts the given array of integers using the
 * counting sort algorithm. It first calculates the maximum value in the array,
 * allocates memory for count and sorted arrays, then populates the count array
 * with the frequency of each element. Next, it modifies the count array to hold
 * the cumulative count of each element. Finally, it uses the count array to place
 * elements in the sorted array and updates the original array with the sorted
 * values.
 */
void counting_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    int max = get_max(array, size);
    int *count = malloc(sizeof(int) * (max + 1));
    if (count == NULL)
        return;

    int *sorted = malloc(sizeof(int) * size);
    if (sorted == NULL)
    {
        free(count);
        return;
    }

    for (size_t i = 0; i < size; i++)
        count[array[i]]++;

    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    print_array(count, max + 1);

    for (int i = size - 1; i >= 0; i--)
    {
        sorted[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (size_t i = 0; i < size; i++)
        array[i] = sorted[i];

    free(sorted);
    free(count);
}

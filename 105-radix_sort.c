#include "sort.h"

void counting_sort(int *array, size_t size, int exp);
int get_max(int *array, size_t size);

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
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
 * counting_sort - Sort an array of integers based on a specific
 *                 significant digit using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @exp: The current exponent (10^k) being considered.
 *
 * Description: This function sorts the array based on the digits
 * at the position determined by the exponent.
 */
void counting_sort(int *array, size_t size, int exp)
{
    int count[10] = {0};
    int output[size];

    /* Count occurrences of digits at the given exponent position */
    for (size_t i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    /* Adjust count array to contain actual positions in the output array */
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    /* Build the output array based on the count array */
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    /* Copy the sorted elements back into the original array */
    for (size_t i = 0; i < size; i++)
        array[i] = output[i];
}

/**
 * radix_sort - Sort an array of integers in ascending order
 *              using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: This function sorts the array using LSD (Least Significant Digit) radix sort.
 * It sorts the array based on individual digits starting from the least significant digit.
 */
void radix_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    int max = get_max(array, size);

    /* Perform counting sort for each significant digit */
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort(array, size, exp);
        print_array(array, size);
    }
}

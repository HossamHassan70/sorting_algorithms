#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Print the elements of an integer array.
 * @array: Pointer to the array of integers.
 * @size: Number of elements in the array.
 */
void print_array(const int *array, size_t size)
{
    if (array == NULL || size == 0)
    {
        printf("\n");
        return;
    }

    printf("%d", array[0]);
    for (size_t i = 1; i < size; ++i)
    {
        printf(", %d", array[i]);
    }
    printf("\n");
}

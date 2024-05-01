#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {100, 93, 40, 57, 14, 58, 85, 54, 31, 56, 46, 39, 15, 26, 78, 13};
    size_t n = sizeof(array) / sizeof(array[0]);

    /* Print the original array */
    print_array(array, n);
    printf("\n");

    /* Sort the array using bitonic sort */
    bitonic_sort(array, n);

    /* Print the sorted array */
    printf("\n");
    print_array(array, n);
    return (0);
}

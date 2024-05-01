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
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t size = sizeof(array) / sizeof(array[0]);

    // Display original array
    printf("Original array:\n");
    print_array(array, size);
    printf("\n");

    /** Perform Heap sort */
    heap_sort(array, size);

    /* Display sorted array */
    printf("\nSorted array:\n");
    print_array(array, size);

    return (0);
}

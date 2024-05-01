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
    /* Initialize the array and its size */
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    /* Print the original array */
    print_array(array, n);
    printf("\n");

    /* Sort the array using Quick Sort (Hoare partition scheme) */
    quick_sort_hoare(array, n);

    /* Print the sorted array */
    printf("\n");
    print_array(array, n);

    return (0);
}

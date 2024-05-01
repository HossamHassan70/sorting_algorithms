#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point of the program.
 *
 * Description: This function serves as the entry point of the program. It initializes
 * an integer array, prints the initial array, performs a quick sort on the array,
 * prints the sorted array, and then returns 0 to indicate successful execution.
 *
 * Return: Always returns 0 to indicate successful execution.
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    printf("Original Array:\n");
    print_array(array, n);
    printf("\n");

    printf("Array after Quick Sort:\n");
    quick_sort(array, n);
    printf("\n");

    printf("Final Sorted Array:\n");
    print_array(array, n);

    return (0);
}

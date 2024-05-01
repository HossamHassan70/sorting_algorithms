#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point of the program
 * Return: Always 0
 *
 * Description: This function serves as the entry point of the program. It
 * initializes an array of integers, prints the original array, sorts it
 * using the counting sort algorithm, prints the sorted array, and returns
 * 0 to indicate successful execution.
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    printf("Original Array:\n");
    print_array(array, n);
    printf("\n");

    printf("Sorted Array:\n");
    counting_sort(array, n);
    printf("\n");
    print_array(array, n);

    return (0);
}

#include "sort.h"

/**
 * merge - Merges two sorted subarrays into one sorted array.
 * @array: The array to be sorted.
 * @temp: Temporary array to store intermediate results.
 * @left: Index of the left subarray.
 * @mid: Index of the middle element.
 * @right: Index of the right subarray.
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
    size_t i = left, j = mid, k = left;

    while (i < mid && j < right) {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    while (i < mid)
        temp[k++] = array[i++];
    while (j < right)
        temp[k++] = array[j++];

    for (i = left; i < right; ++i)
        array[i] = temp[i];
}

/**
 * merge_sort_recursive - Recursively sorts the array using merge sort.
 * @array: The array to be sorted.
 * @temp: Temporary array to store intermediate results.
 * @left: Index of the leftmost element.
 * @right: Index of the rightmost element.
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
    if (right - left <= 1)
        return;

    size_t mid = left + (right - left) / 2;

    merge_sort_recursive(array, temp, left, mid);
    merge_sort_recursive(array, temp, mid, right);
    merge(array, temp, left, mid, right);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using merge sort.
 * @array: The array to be sorted.
 * @size: Size of the array.
 *
 * Description: Implements the merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    int *temp = malloc(sizeof(int) * size);
    if (temp == NULL)
        return;

    merge_sort_recursive(array, temp, 0, size);

    free(temp);
}

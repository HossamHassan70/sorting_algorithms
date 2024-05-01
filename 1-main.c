#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * create_listint - Creates a doubly linked list from an array of integers.
 *
 * @array: Pointer to the array to convert to a doubly linked list.
 * @size: Size of the array.
 *
 * Return: Pointer to the head of the created list. NULL on failure.
 */
listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list = NULL;
    listint_t *node;

    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);

        node->n = array[size];
        node->prev = NULL;
        node->next = list;

        if (list)
            list->prev = node;

        list = node;
    }

    return (list);
}

/**
 * main - Entry point of the program.
 *
 * Return: Always returns 0 to indicate successful execution.
 */
int main(void)
{
    listint_t *list;
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    list = create_listint(array, n);
    if (!list)
        return (1);

    printf("Original List:\n");
    print_list(list);
    printf("\n");

    printf("Sorted List:\n");
    insertion_sort_list(&list);
    printf("\n");

    printf("Final Sorted List:\n");
    print_list(list);

    return (0);
}

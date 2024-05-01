#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * create_listint - Creates a doubly linked list from an array of integers
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 * Return: Pointer to the first element of the created list. NULL on failure
 *
 * Description: This function takes an array of integers and converts it into
 * a doubly linked list. It allocates memory for each node, assigns the values
 * from the array to the nodes, and links them together to form the list.
 */
listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list = NULL, *node = NULL;

    for (size_t i = 0; i < size; i++)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        node->n = array[i];
        node->next = list;
        node->prev = NULL;
        if (list != NULL)
            list->prev = node;
        list = node;
    }
    return (list);
}

/**
 * main - Entry point of the program
 * Return: Always 0
 *
 * Description: This function serves as the entry point of the program. It
 * initializes an array of integers, creates a doubly linked list from the
 * array, prints the original list, sorts it using the cocktail sort algorithm,
 * prints the sorted list, and returns 0 to indicate successful execution.
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);
    listint_t *list = create_listint(array, n);

    if (!list)
        return (1);

    printf("Original List:\n");
    print_list(list);
    printf("\n");

    printf("Sorted List:\n");
    cocktail_sort_list(&list);
    printf("\n");
    print_list(list);

    return (0);
}

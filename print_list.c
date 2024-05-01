#include <stdio.h>
#include "sort.h"

/**
 * print_list - Print the elements of a linked list.
 * @list: Pointer to the head of the linked list.
 */
void print_list(const listint_t *list)
{
    if (list == NULL)
    {
        printf("\n");
        return;
    }

    printf("%d", list->n);
    list = list->next;

    while (list != NULL)
    {
        printf(", %d", list->n);
        list = list->next;
    }

    printf("\n");
}

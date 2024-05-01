#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @h: Pointer to the head of the doubly linked list.
 * @n1: Pointer to the first node to swap.
 * @n2: Pointer to the second node to swap.
 *
 * Description: This function swaps two nodes in a doubly linked list.
 * It updates the links of the adjacent nodes accordingly.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t **n2)
{
    if (*n1 == *n2)
        return;

    if ((*n1)->prev != NULL)
        (*n1)->prev->next = *n2;
    else
        *h = *n2;

    if ((*n2)->next != NULL)
        (*n2)->next->prev = *n1;

    (*n1)->next = (*n2)->next;
    (*n2)->prev = (*n1)->prev;
    (*n1)->prev = *n2;
    (*n2)->next = *n1;
}

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort.
 * @list: Pointer to the head of the doubly linked list.
 *
 * Description: This function sorts a doubly linked list of integers
 * using the insertion sort algorithm. It iterates through the list,
 * inserting each node into its correct position by comparing its value
 * with the values of previous nodes. It prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current = (*list)->next;

    while (current != NULL)
    {
        listint_t *temp = current->prev;
        listint_t *key = current;

        while (temp != NULL && temp->n > key->n)
        {
            swap_nodes(list, &temp, &key);
            temp = key->prev;
            print_list((const listint_t *)*list);
        }

        current = current->next;
    }
}

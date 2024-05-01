#include "sort.h"

void swap_nodes(listint_t **list, listint_t **tail, listint_t **current);

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @list: A pointer to the head of the doubly-linked list.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @current: A pointer to the current swapping node of the cocktail shaker algo.
 *
 * Description: This function swaps the current node with the next or previous
 * node based on the direction of traversal in the cocktail shaker algorithm.
 */
void swap_nodes(listint_t **list, listint_t **tail, listint_t **current)
{
    listint_t *tmp = (*current)->next;

    if ((*current)->prev != NULL)
        (*current)->prev->next = tmp;
    else
        *list = tmp;

    if (tmp != NULL)
        tmp->prev = (*current)->prev;
    else
        *tail = (*current)->prev;

    (*current)->next = tmp != NULL ? tmp->next : NULL;

    if (tmp != NULL && tmp->next != NULL)
        tmp->next->prev = *current;

    (*current)->prev = tmp;

    if (tmp != NULL)
        tmp->next = *current;

    *current = tmp;
}

/**
 * cocktail_sort_list - Sorts a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of the list.
 *
 * Description: This function sorts a doubly-linked list of integers in ascending
 * order using the cocktail shaker sort algorithm. It repeatedly traverses the list
 * from both ends, swapping adjacent nodes to move larger elements towards the end
 * and smaller elements towards the beginning. It stops when no more swaps are needed.
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *tail, *current;
    bool sorted = false;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    for (tail = *list; tail->next != NULL; tail = tail->next)
        ;

    while (!sorted)
    {
        sorted = true;
        for (current = *list; current != tail; current = current->next)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(list, &tail, &current);
                print_list((const listint_t *)*list);
                sorted = false;
            }
        }
        if (sorted)
            break;
        sorted = true;
        for (current = tail; current != *list; current = current->prev)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(list, &tail, &current);
                print_list((const listint_t *)*list);
                sorted = false;
            }
        }
    }
}

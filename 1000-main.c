#include <stdlib.h>
#include <stdio.h>
#include "deck.h"

/**
 * print_deck - Print the deck of cards.
 * @deck: Pointer to the head of the deck.
 */
void print_deck(const deck_node_t *deck)
{
    size_t i = 0;
    char suits[4] = {'S', 'H', 'C', 'D'};

    while (deck)
    {
        if (i > 0)
            printf(", ");
        printf("{%s, %c}", deck->card->value, suits[deck->card->kind]);
        if (++i % 13 == 0)
            printf("\n");
        deck = deck->next;
    }
}

/**
 * init_deck - Initialize the deck of cards.
 * @cards: Array of card_t structures representing the cards.
 *
 * Return: Pointer to the head of the initialized deck.
 */
deck_node_t *init_deck(const card_t cards[52])
{
    deck_node_t *deck = NULL;

    for (int i = 51; i >= 0; i--)
    {
        deck_node_t *node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        node->card = &cards[i];
        node->prev = NULL;
        node->next = deck;
        if (deck)
            deck->prev = node;
        deck = node;
    }
    return (deck);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    card_t cards[52] = {
        {"Jack", CLUB}, {"4", HEART}, {"3", HEART}, {"3", DIAMOND}, {"Queen", HEART}, {"5", HEART}, {"5", SPADE}, {"10", HEART}, {"6", HEART}, {"5", DIAMOND}, {"6", SPADE}, {"9", HEART}, {"7", DIAMOND}, {"Jack", SPADE}, {"Ace", DIAMOND}, {"9", CLUB}, {"Jack", DIAMOND}, {"7", SPADE}, {"King", DIAMOND}, {"10", CLUB}, {"King", SPADE}, {"8", CLUB}, {"9", SPADE}, {"6", CLUB}, {"Ace", CLUB}, {"3", SPADE}, {"8", SPADE}, {"9", DIAMOND}, {"2", HEART}, {"4", DIAMOND}, {"6", DIAMOND}, {"3", CLUB}, {"Queen", CLUB}, {"10", SPADE}, {"8", DIAMOND}, {"8", HEART}, {"Ace", SPADE}, {"Jack", HEART}, {"2", CLUB}, {"4", SPADE}, {"2", SPADE}, {"2", DIAMOND}, {"King", CLUB}, {"Queen", SPADE}, {"Queen", DIAMOND}, {"7", CLUB}, {"7", HEART}, {"5", CLUB}, {"10", DIAMOND}, {"4", CLUB}, {"King", HEART}, {"Ace", HEART},
    };
    deck_node_t *deck;

    deck = init_deck(cards);
    print_deck(deck);
    printf("\n");
    sort_deck(&deck);
    printf("\n");
    print_deck(deck);
    return (0);
}

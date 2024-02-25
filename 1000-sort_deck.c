#include "deck.h"

/**
 * convert_to_int - converts the name of the card to the int value.
 * @card_name: the string that represents the card's name.
 *
 * Return: the int value of the card's name.
 */
int convert_to_int(const char *card_name)
{
	int i;

	value_num values[14] = {
		{"Ace", 1}, {"2", 2}, {"3", 3}, {"4", 4},
		{"5", 5}, {"6", 6}, {"7", 7}, {"8", 8},
		{"9", 9}, {"10", 10}, {"Jack", 11}, {"Queen", 12},
		{"King", 13}, {NULL, -1}
	};
	for (i = 0; values[i].valuename != NULL; i++)
	{
		if (strcmp(card_name, values[i].valuename) == 0)
			return (values[i].valuenum);
	}
	return (-1);
}

/**
 * sort_by_type - sorts a set of cards (Spades, Hearts, Clubs, Diamonds)
 * according to its value (Ace to King).
 * @setpointer: the pointer to the beginning node of the set.
 * @deck: the pointer to the first node of the deck.
 *
 * Return: void.
 */
void sort_by_type(deck_node_t **setpointer, deck_node_t **deck)
{
	deck_node_t *comp1, *comp2;
	int i, j;

	for (i = 12; i > 0; i--)
	{
		comp1 = *setpointer;
		comp2 = (*setpointer)->next;
		for (j = 0; j < i; j++)
		{
			if (convert_to_int(comp1->card->value) >
			    convert_to_int(comp2->card->value))
			{
				if (comp1->prev == NULL)
					*deck = comp2;
				if (comp1 == *setpointer)
					*setpointer = comp2;
				comp1->next = comp2->next;
				comp2->prev = comp1->prev;
				comp1->prev = comp2;
				comp2->next = comp1;
				if (comp2->prev)
					comp2->prev->next = comp2;
				if (comp1->next)
					comp1->next->prev = comp1;
				comp2 = comp1->next;
				continue;
			}
			comp1 = comp1->next;
			comp2 = comp2->next;
		}
	}

}

/**
 * sort_by_kind - sorts a deck of cards into 4 sets by kind
 * (Spades, Hearts, Clubs, Diamonds).
 * @deck: the pointer to the beginning node of the deck.
 *
 * Return: void.
 */
void sort_by_kind(deck_node_t **deck)
{
	deck_node_t *comp1, *comp2;
	int i, j;

	for (i = 51; i > 0; i--)
	{
		comp1 = *deck;
		comp2 = (*deck)->next;

		for (j = 0; j < i; j++)
		{
			if (comp1->card->kind > comp2->card->kind)
			{
				if (comp1->prev == NULL)
					*deck = comp2;
				comp1->next = comp2->next;
				comp2->prev = comp1->prev;
				comp1->prev = comp2;
				comp2->next = comp1;
				if (comp2->prev)
					comp2->prev->next = comp2;
				if (comp1->next)
					comp1->next->prev = comp1;
				comp2 = comp1->next;
			}
			else
			{
				comp1 = comp1->next;
				comp2 = comp2->next;
			}
		}
	}
}

/**
 * set_pointers - sets the pointers to the beginning
 * node of a set (S, H, C, D).
 * @deck: the beginning node of the set before it.
 *
 * Return: deck node pointer to the beginning of the list.
 */
deck_node_t *set_pointers(deck_node_t *deck)
{
	int i;
	deck_node_t *cursor;

	cursor = deck;
	for (i = 0; i < 13; i++)
	{
		cursor = cursor->next;
	}
	return (cursor);
}

/**
 * sort_deck - sorts a deck of cards using 2 keys:
 * the values of the cards and the kind of every card.
 * @deck: the double pointer to the first node of the unsorted deck.
 * Return: void.
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *set1, *set2, *set3, *set4;

	sort_by_kind(deck);

	set1 = *deck;
	set2 = set_pointers(set1);
	set3 = set_pointers(set2);
	set4 = set_pointers(set3);
	sort_by_type(&set1, deck);
	sort_by_type(&set2, deck);
	sort_by_type(&set3, deck);
	sort_by_type(&set4, deck);
}

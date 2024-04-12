#include "sort.h"

/**
 * get_head - gets the head of the list
 * @list: the list to retrieve the head from
 * Return: the head of the list
 */
listint_t *get_head(listint_t *list)
{
    listint_t *tmp = list;

    while (tmp && tmp->prev)
    {
        tmp = tmp->prev;
    }

    return tmp;
}

/**
 * swap_dll - swaps nodes in a doubly linked list
 * @left: left node to be swapped
 * @right: right node to be swapped
 * Return: 0 if successful, 1 if failure
 */
int swap_dll(listint_t *left, listint_t *right)
{
    if (!left || !right)
    {
        return 1; /* Using 1 instead of EXIT_FAILURE for portability */
    }

    if (left->prev)
    {
        left->prev->next = right;
    }

    if (right->next)
    {
        right->next->prev = left;
    }

    left->next = right->next;
    right->prev = left->prev;
    left->prev = right;
    right->next = left;

    return 0; /* Using 0 instead of EXIT_SUCCESS for portability */
}

/**
 * insertion_sort_list - sorts a doubly linked list using the insertion sort algorithm
 * @list: double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *big_step, *small_step;
    unsigned int big_savespot, small_savespot, i, stat;

    if (!list || !*list)
    {
        return;
    }

    big_step = small_step = *list;
    big_savespot = small_savespot = i = 0;

    while (big_step)
    {
        small_step = big_step;
        small_savespot = big_savespot;

        while (small_step->prev && small_step->n < small_step->prev->n)
        {
            stat = swap_dll(small_step->prev, small_step);

            if (stat == 1)
            {
                return;
            }

            small_step = get_head(*list);

            for (i = 0; i < small_savespot; ++i)
            {
                small_step = small_step->next;
            }

            small_step = small_step->prev;
            --small_savespot;

            print_list(get_head(*list));
        }

        big_step = get_head(*list);

        for (i = 0; i < big_savespot; ++i)
        {
            big_step = big_step->next;
        }

        ++big_savespot;
        big_step = big_step->next;
    }

    *list = get_head(*list);
}

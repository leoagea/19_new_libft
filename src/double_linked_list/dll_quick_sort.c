/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_quick_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:11:54 by lagea             #+#    #+#             */
/*   Updated: 2025/06/02 19:24:03 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void dll_quick_sort(t_dll *list, int (*cmp)(void *, void *))
{
    if (!list || !list->head || !list->tail || list->head == list->tail)
        return;

    t_node *pivot = list->head;
    t_dll left;
    t_dll right;
    dll_init(&left);
    dll_init(&right);

    t_node *current = list->head->next;
    t_node *next;

    while (current) {
        next = current->next;
        if (cmp(current->content, pivot->content) < 0) {
            current->prev->next = current->next;
            if (current->next)
                current->next->prev = current->prev;
            current->next = NULL;
            current->prev = left.tail;
            if (!left.head)
                left.head = current;
            if (left.tail)
                left.tail->next = current;
            left.tail = current;
            left.size++;
        } else {
            current->prev->next = current->next;
            if (current->next)
                current->next->prev = current->prev;
            current->next = NULL;
            current->prev = right.tail;
            if (!right.head)
                right.head = current;
            if (right.tail)
                right.tail->next = current;
            right.tail = current;
            right.size++;
        }
        current = next;
    }

    // Recursively sort sublists
    dll_quick_sort(&left, cmp);
    dll_quick_sort(&right, cmp);

    // Reconstruct the main list
    list->head = left.head ? left.head : pivot;
    if (left.tail) {
        left.tail->next = pivot;
        pivot->prev = left.tail;
    } else {
        pivot->prev = NULL;
    }

    pivot->next = right.head;
    if (right.head) {
        right.head->prev = pivot;
        list->tail = right.tail;
    } else {
        list->tail = pivot;
    }
}

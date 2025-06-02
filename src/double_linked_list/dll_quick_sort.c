/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_quick_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:11:54 by lagea             #+#    #+#             */
/*   Updated: 2025/06/02 18:28:49 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void dll_quick_sort(t_dll *list, int (*cmp)(void *, void *))
{
	if (!list || !list->head || !list->tail || list->head == list->tail)
		return;

	t_node *pivot = list->head;
	t_dll left;
	dll_init(&left);
	// t_node *left = NULL;
	t_dll right;
	dll_init(&right);
	// t_node *right = NULL;
	t_node *current = list->head->next;

	while (current) {
		if (cmp(current->content, pivot->content) < 0) {
			dll_insert_tail(current->content, &left);
		} else {
			dll_insert_tail(current->content, &right);
		}
		current = current->next;
	}

	dll_quick_sort(&left, cmp);
	dll_quick_sort(&right, cmp);

	list->head = left.size != 0 ? left.head : pivot;
	if (left.size > 0) {
		left.tail->next = pivot;
		pivot->prev = left.tail;
	}
	pivot->next = right.size != 0 ? right.head : NULL;
	if (right.size > 0) {
		right.head->prev = pivot;
		list->tail = right.tail;
	} else {
		list->tail = pivot;
	}
}

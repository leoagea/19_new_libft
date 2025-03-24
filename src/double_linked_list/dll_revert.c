/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_revert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:50:45 by lagea             #+#    #+#             */
/*   Updated: 2025/03/24 19:02:20 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void dll_revert(t_dll *dll)
{
    if (!dll || !dll->head || dll->head == dll->tail)
        return;

    t_node *current = dll->head;
    t_node *temp = NULL;

    while (current != NULL)
    {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;

        current = temp;
    }

    temp = dll->head;
    dll->head = dll->tail;
    dll->tail = temp;
}
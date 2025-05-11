/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_insert_tail.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:34:55 by lagea             #+#    #+#             */
/*   Updated: 2025/05/11 19:15:28 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	dll_insert_tail(void *data, t_dll *dll)
{
	t_node	*new;

	new = dll_new_node(data);
	if (new == NULL)
	{
		dll_clear(dll);
		return ;
	}
	if (dll->tail == NULL)
	{
		dll->head = new;
		dll->tail = new;
		dll->size = 1;
	}
	else
	{
		new->prev = dll->tail;
		dll->tail->next = new;
		dll->tail = new;
		dll->size++;
	}
}

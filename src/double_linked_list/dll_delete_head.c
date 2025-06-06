/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_delete_head.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 00:18:01 by lagea             #+#    #+#             */
/*   Updated: 2025/06/06 14:23:19 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	dll_delete_head(t_dll *dll)
{
	t_node	*temp;

	temp = dll->head;
	if (dll->head == dll->tail)
	{
		dll->head = NULL;
		dll->tail = NULL;
		free(temp);
	}
	else
	{
		dll->head = temp->next;
		dll->head->prev = NULL;
		free(temp);
	}
	dll->size--;
}

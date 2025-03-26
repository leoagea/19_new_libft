/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:35:09 by lagea             #+#    #+#             */
/*   Updated: 2025/03/26 22:36:17 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void dll_free(t_dll *dll, void (*free_content)(void *))
{
	t_node	*node;
	t_node	*next;

	node = dll->head;
	while (node)
	{
		next = node->next;
		free_content(node->content);
		free(node);
		node = next;
	}
	dll->head = NULL;
	dll->tail = NULL;
}

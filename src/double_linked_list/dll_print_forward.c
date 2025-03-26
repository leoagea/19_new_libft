/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_print_forward.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:25:39 by lagea             #+#    #+#             */
/*   Updated: 2025/03/26 22:27:23 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	dll_print_forward(t_dll *dll, void (*print)(void *))
{
	t_node	*node;

	node = dll->head;
	while (node)
	{
		print(node->content);
		node = node->next;
	}
}

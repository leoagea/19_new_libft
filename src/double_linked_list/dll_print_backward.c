/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_print_backward.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:32:34 by lagea             #+#    #+#             */
/*   Updated: 2025/03/26 22:32:55 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void dll_print_backward(t_dll *dll, void (*print)(void *))
{
	t_node	*node;

	node = dll->tail;
	while (node)
	{
		print(node->content);
		node = node->prev;
	}
}

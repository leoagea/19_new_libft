/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elements_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 23:42:38 by lagea             #+#    #+#             */
/*   Updated: 2025/03/24 17:41:57 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_print_hex_add(unsigned long n)
{
	char	*base_16;

	base_16 = "0123456789abcdef";
	if (n < 16)
		return (ft_print_char(base_16[n]));
	else
	{
		if (ft_print_hex_add((unsigned long)n / 16))
			return (ft_print_char(base_16[n % 16]));
	}
	return (-1);
}

int	ft_print_add(unsigned long add)
{
	write(1, "0x", 2);
	ft_print_hex_add(add);
	return (ft_add_len(add) + 2);
}

int ft_print_bool(int valbool)
{
	if (valbool == 1)
		return (write(1, "true", 4), 4);
	else
		return (write(1, "false", 5), 5);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:03:36 by lagea             #+#    #+#             */
/*   Updated: 2024/08/16 12:52:50 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	print_unb(unsigned int n, int fd)
{
	if (n / 10)
	{
		print_unb(n / 10, fd);
		print_unb(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

void	ft_putunbr_fd(unsigned int n, int fd)
{
	unsigned long	nbr;

	if (fd < 0)
		return ;
	nbr = (unsigned long)n;
	print_unb(nbr, fd);
}

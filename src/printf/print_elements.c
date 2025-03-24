/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:27:13 by lagea             #+#    #+#             */
/*   Updated: 2025/03/24 20:06:04 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include "printf.h"

int	ft_print_char(int fd, char c)
{
	return (write(fd, &c, 1));
}

int	ft_print_string(int fd, char *s)
{
	if (!s)
		return (write(fd, "(null)", 6));
	return (write(fd, s, ft_strlen(s)));
}

int	ft_print_decimal(int fd, int n)
{
	ft_putnbr_fd(n, fd);
	return (ft_int_len((int)n));
}

int	ft_print_udecimal(int fd, unsigned int n)
{
	ft_putunbr_fd(n, fd);
	return (ft_int_len((unsigned int)n));
}

int	ft_print_hex(int fd, unsigned int n, char *base)
{
	if (n < 16)
		return (ft_print_char(fd, base[n]));
	else
	{
		if (ft_print_hex(fd, ((unsigned int)n / 16), base))
			ft_print_char(fd, base[n % 16]);
	}
	return (ft_hex_len(n));
}

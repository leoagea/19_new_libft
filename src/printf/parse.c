/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:06:36 by lagea             #+#    #+#             */
/*   Updated: 2025/03/27 01:22:54 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_check_next_char(const char *s, int i)
{
	if (s[i] == 'c' || s[i] == 's' || s[i] == 'p' || s[i] == 'd' 
		|| s[i] == 'i' || s[i] == 'u' || s[i] == 'x' || s[i] == 'X' 
		|| s[i] == '%' || s[i] == 'b' || (s[i] == 'l' && s[i + 1] == 'l' 
        && (s[i + 2] == 'd' || s[i + 2] == 'i' || s[i + 2] == 'u')))
        return (1);
	return (0);
}

int	ft_parse_printf(int fd, const char *s, int *i, va_list *par)
{
	if (s[*i + 1] == 'c')
		return (ft_print_char(fd, va_arg(*par, int)));
	else if (s[*i + 1] == 's')
		return (ft_print_string(fd, va_arg(*par, char *)));
	else if (s[*i + 1] == 'p')
		return (ft_print_add(fd, va_arg(*par, unsigned long)));
	else if (s[*i + 1] == 'd' || s[*i + 1] == 'i')
		return (ft_print_decimal(fd, va_arg(*par, int)));
	else if (s[*i + 1] == 'u')
		return (ft_print_udecimal(fd, va_arg(*par, unsigned int)));
	else if (s[*i + 1] == 'x')
		return (ft_print_hex(fd,va_arg(*par, long), "0123456789abcdef"));
	else if (s[*i + 1] == 'X')
		return (ft_print_hex(fd, va_arg(*par, long), "0123456789ABCDEF"));
	else if (s[*i + 1] == '%')
		return (write(fd, "%", 1));
	else if (s[*i + 1] == 'b')
		return (ft_print_bool(fd, va_arg(*par, int)));
	else if (s[*i + 1] == 'l' && s[*i + 2] == 'l' && (s[*i + 3] == 'd' || s[*i + 3] == 'i'))
	{
		*i = *i + 2;
		return (ft_print_longlong(fd, va_arg(*par, long long)));
	}
	else if (s[*i + 1] == 'l' && s[*i + 2] == 'l' && s[*i + 3] == 'u')
	{
		*i = *i + 2;
		return (ft_print_ulonglong(fd, va_arg(*par, unsigned long long)));
	}
	else
		return (0);
}

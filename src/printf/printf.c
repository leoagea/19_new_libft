/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:06:25 by lagea             #+#    #+#             */
/*   Updated: 2025/03/27 01:47:50 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include "printf.h"

/*
	%c : char
	%s : string
	%p : pointer
	%d : decimal
	%i : integer
	%u : unsigned decimal
	%x : hexadecimal
	%X : hexadecimal
	%% : percent
	%b : binary
	%lld %lli : long long decimal
	%llu : long long unsigned decimal
*/
int	ft_printf(int fd, const char *s, ...)
{
	int		temp;
	int		index;
	va_list	arg;

	temp = 0;
	index = 0;
	if (fd < 0)
		return (write(2, ERROR_PRINTF, 51), -1);
	va_start(arg, s);
	while (s[index])
	{
		if (s[index] == '%' && ft_check_next_char(s, index))
		{
			temp += ft_parse_printf(fd, s, &index, &arg);
			index++;
		}
		else
			temp += ft_print_char(fd, s[index]);
		index++;
	}
	va_end(arg);
	return (temp);
}

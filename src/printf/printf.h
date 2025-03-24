/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:55:10 by lagea             #+#    #+#             */
/*   Updated: 2025/03/24 20:06:47 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>

/*---------------------------------PARSE---------------------------------*/

int	ft_check_next_char(const char *s, int index);
int	ft_parse_printf(int fd, const char *s, int index, va_list *par);

/*----------------------------PRINT_ELEMENTS-----------------------------*/

int	ft_print_char(int fd, char c);
int	ft_print_string(int fd, char *s);
int	ft_print_decimal(int fd, int n);
int	ft_print_udecimal(int fd, unsigned int n);
int	ft_print_hex(int fd, unsigned int n, char *base);

/*---------------------------PRINT_ELEMENTS_2----------------------------*/

int	ft_print_hex_add(int fd, unsigned long n);
int	ft_print_add(int fd, unsigned long add);
int ft_print_bool(int fd,int valbool);


/*-------------------------------UTILS_LEN--------------------------------*/

int	ft_int_len(long n);
int	ft_add_len(unsigned long add);
int	ft_hex_len(unsigned int hex);

#endif
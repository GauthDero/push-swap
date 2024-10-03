/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdero <gdero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:55:51 by gdero             #+#    #+#             */
/*   Updated: 2023/12/28 15:47:42 by gdero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

int	ft_printf(const char *format, ...);
int	format_and_print(const char *format, va_list ap, int *len_string);
int	ft_putnbr(int nb, int *len_string);
int	putnbrun(unsigned int nb, int *len_string);
int	print_nb(long nb, int *len_string);
int	hexa(unsigned int number, char format, int *len_string);
int	hexa_ptr(unsigned long number, int *len_string);
int	hexa_lower(unsigned int number, int *len_string);
int	hexa_upper(unsigned int number, int *len_string);
int	hexa_len(unsigned int number);
int	ft_putchar(int c, int *len_string);
int	putstr(char *s, int *len_string);
int	while_loop(const char *format, int index, va_list ap, int *len_string);
int	transform_hexa(unsigned long number, int *len_string);

#endif

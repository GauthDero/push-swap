/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdero <gdero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:09:44 by gdero             #+#    #+#             */
/*   Updated: 2023/12/28 15:28:58 by gdero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nb(long nb, int *len_string)
{
	long	nb2;

	nb2 = nb % 10 + '0';
	if (nb / 10 > 0)
	{
		if (print_nb(nb / 10, len_string))
			return (1);
	}
	return (ft_putchar(nb2, len_string));
}

int	putnbrun(unsigned int nb, int *len_string)
{
	if (nb == 0)
	{
		if (ft_putchar('0', len_string))
			return (1);
		return (0);
	}
	if (nb > 0)
		if (print_nb(nb, len_string))
			return (1);
	if (nb < 0)
	{
		nb *= -1;
		if (print_nb((4294967296 - nb), len_string))
			return (1);
	}
	return (0);
}

int	ft_putnbr(int nb, int *len_string)
{
	long	i;

	i = nb;
	if (nb == 0)
	{
		if (ft_putchar('0', len_string))
			return (1);
		return (0);
	}
	if (i < 0)
	{
		if (ft_putchar('-', len_string))
			return (1);
		i *= -1;
	}
	if (print_nb(i, len_string))
		return (1);
	return (0);
}

int	while_loop(const char *format, int index, va_list ap, int *len_string)
{
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			if (format_and_print(&format[index + 1], ap, len_string))
				return (-1);
			index++;
		}
		else
			if (ft_putchar(format[index], len_string))
				return (-1);
		index++;
	}
	return (0);
}

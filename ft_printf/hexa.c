/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdero <gdero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:01:06 by gdero             #+#    #+#             */
/*   Updated: 2024/01/06 16:59:59 by gdero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexa_len(unsigned int number)
{
	int	counter;

	counter = 0;
	while (number != 0)
	{
		number = number / 16;
		counter++;
	}
	return (counter);
}

int	hexa_upper(unsigned int number, int *len_string)
{
	unsigned long	r;
	int				i;
	int				cifers;
	char			hexa[16];

	i = 0;
	cifers = 0;
	while (number != 0)
	{
		r = number % 16;
		if (r < 10)
			hexa[cifers] = r + 48;
		else
			hexa[cifers] = r + 55;
		number = number / 16;
		cifers++;
	}
	i = cifers;
	while (i--)
	{
		if (ft_putchar(hexa[i], len_string))
			return (1);
	}
	return (0);
}

int	hexa_lower(unsigned int number, int *len_string)
{
	unsigned long	r;
	int				i;
	int				cifers;
	char			hexa[16];

	i = 0;
	cifers = 0;
	while (number != 0)
	{
		r = number % 16;
		if (r < 10)
			hexa[cifers] = r + 48;
		else
			hexa[cifers] = r + 87;
		number = number / 16;
		cifers++;
	}
	i = cifers;
	while (i--)
	{
		if (ft_putchar(hexa[i], len_string))
			return (1);
	}
	return (0);
}

int	transform_hexa(unsigned long number, int *len_string)
{
	unsigned long	r;
	int				i;
	int				cifers;
	char			hexa[16];

	i = 0;
	cifers = 0;
	while (number != 0)
	{
		r = number % 16;
		if (r < 10)
			hexa[cifers] = r + 48;
		else
			hexa[cifers] = r + 87;
		number = number / 16;
		cifers++;
	}
	i = cifers;
	while (i--)
	{
		if (ft_putchar(hexa[i], len_string))
			return (1);
	}
	return (0);
}

int	hexa_ptr(unsigned long number, int *len_string)
{
	if (putstr("0x", len_string))
		return (1);
	if (number == 0)
	{
		if (ft_putchar('0', len_string))
			return (1);
		return (0);
	}
	if (transform_hexa(number, len_string))
		return (1);
	return (0);
}

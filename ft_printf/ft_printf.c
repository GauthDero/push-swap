/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdero <gdero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:51:20 by gdero             #+#    #+#             */
/*   Updated: 2024/02/18 16:49:31 by gdero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c, int *len_string)
{
	if (write(1, &c, 1) == -1)
		return (1);
	*len_string = *len_string + 1;
	return (0);
}

int	putstr(char *s, int *len_string)
{
	if (s == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (1);
		*len_string = *len_string + 6;
		return (0);
	}
	while (*s != '\0')
	{
		if (ft_putchar(*s, len_string))
			return (1);
		s++;
	}
	return (0);
}

int	hexa(unsigned int number, char format, int *len_string)
{
	int	num_len;

	num_len = hexa_len(number);
	if (number == 0)
	{
		if (ft_putchar('0', len_string))
			return (1);
		return (0);
	}
	if (format == 'x')
	{
		if (hexa_lower(number, len_string))
			return (1);
	}
	else
	{
		if (hexa_upper(number, len_string))
			return (1);
	}
	return (0);
}

int	format_and_print(const char *format, va_list ap, int *len_string)
{
	if (*format == '%' && ft_putchar('%', len_string))
		return (1);
	else if (*format == 'c' && ft_putchar(va_arg(ap, int), len_string))
		return (1);
	else if (*format == 's' && putstr(va_arg(ap, char *), len_string))
		return (1);
	else if ((*format == 'd' || *format == 'i') \
	&& ft_putnbr(va_arg(ap, int), len_string))
		return (1);
	else if (*format == 'u' && putnbrun(va_arg(ap, unsigned int), len_string))
		return (1);
	else if ((*format == 'x' || *format == 'X') \
	&& hexa(va_arg(ap, unsigned int), *format, len_string))
		return (1);
	else if (*format == 'p' && hexa_ptr(va_arg(ap, unsigned long), len_string))
		return (1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		char_num;
	int		*len_string;
	int		index;

	char_num = 0;
	len_string = &char_num;
	index = 0;
	if (format == NULL || *format == '\0')
		return (0);
	va_start(ap, format);
	if (while_loop(format, index, ap, len_string) == -1)
		return (-1);
	va_end(ap);
	return (*len_string);
}

/*int main(void)
{
	printf("test\n");
	ft_printf("%d %u %s %c %x\n", -12, -12, "salut", 'c', 145);
	printf("%d %u %s %c %x\n", -12, -12, "salut", 'c', 145);
}*/

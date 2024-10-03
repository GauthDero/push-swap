/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdero <gdero@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:18:05 by gdero             #+#    #+#             */
/*   Updated: 2024/04/01 17:12:57 by gdero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi_2(const char *str)
{
	int			neg;
	long long	result;

	neg = 1;
	result = 0;
	while (*str == 32 || ((*str > 8 && *str < 14)))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = neg * -1;
		str++;
	}
	while (*str > 47 && *str < 58)
	{
		result = 10 * result + (*str - '0');
		str++;
	}
	return (result * neg);
}

bool	check_ints(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < argc)
	{
		while (argv[j][i])
		{
			if (argv[j][i] == 45 && argv[j][i + 1] == 45)
				return (false);
			if ((argv[j][i] < 48 || argv[j][i] > 57) && argv[j][i] != 45)
				return (false);
			if (argv[j][i] == 45 && !argv[j][i + 1])
				return (false);
			if (argv[j][i] == 45 && ((argv[j][i - 1] > 48 \
			&& argv[j][i - 1] < 57)))
				return (false);
			i++;
		}
		j++;
		i = 0;
	}
	return (true);
}

bool	check_null(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (argv[i][0] == 0)
			return (false);
		i++;
	}
	return (true);
}

long long	*int_args(int argc, char **argv)
{
	int			i;
	long long	*array_int;

	i = 1;
	if (!check_ints(argc, argv) || !check_null(argc, argv))
		return (NULL);
	array_int = malloc((argc) * sizeof(long));
	if (!array_int)
		return (NULL);
	while (i < argc)
	{
		array_int[i - 1] = ft_atoi_2(argv[i]);
		i++;
	}
	array_int[argc - 1] = 0;
	return (array_int);
}

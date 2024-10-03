/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdero <gdero@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:21:50 by gdero             #+#    #+#             */
/*   Updated: 2024/04/01 17:14:10 by gdero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_string(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] < 48 || argv[1][i] > 57)
		{
			if (argv[1][i] == 45 && argv[1][i - 1] != 32 && i != 0)
				return (false);
			if (argv[1][i] != 32 && argv[1][i] != 45)
				return (false);
			if (argv[1][i] == 45 && ((argv[1][i - 1] > 48 \
			&& argv[1][i - 1] < 57)))
				return (false);
			if (argv[1][i] == 45 && argv[1][i + 1] == 32)
				return (false);
		}
		i++;
	}
	return (true);
}

void	fill_array(long long *array_int, char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		array_int[i] = ft_atoi_2(numbers[i]);
		i++;
	}
	array_int[i] = 0;
	i = 0;
	while (numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
}

long long	*string_arg(char **argv)
{
	int			i;
	char		**numbers;
	long long	*array_int;

	i = 0;
	if (!check_string(argv))
		return (NULL);
	numbers = ft_split(argv[1], ' ');
	if (!numbers)
		return (NULL);
	if (numbers[0] == (void *)0)
	{
		free(numbers);
		return (NULL);
	}
	while (numbers[i])
		i++;
	array_int = malloc((i + 1) * sizeof(long long));
	if (!array_int)
	{
		free(numbers);
		return (NULL);
	}
	fill_array(array_int, numbers);
	return (array_int);
}

long	nb_split2(char const *string, char sep)
{
	long	counter;

	counter = 0;
	while (*string != '\0')
	{
		while (*string == sep && *string != '\0')
			string++;
		if (*string != '\0')
			counter++;
		while (*string != sep && *string != '\0')
			string++;
	}
	return (counter);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdero <gdero@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:19:23 by gdero             #+#    #+#             */
/*   Updated: 2024/04/01 17:13:21 by gdero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	array_is_sorted(long long *array_a, int argc)
{
	long long	i;

	i = 0;
	while (i < argc - 2)
	{
		if (array_a[i] > array_a[i + 1])
			return (false);
		i++;
	}
	return (true);
}

long long	*change_numbers(long long *array, int nb_numbers)
{
	long long	i;
	long long	j;
	long long	counter;
	long long	*new_array;

	i = 0;
	j = 0;
	new_array = malloc((nb_numbers + 1) * sizeof(long));
	if (!new_array)
		return (NULL);
	while (i < nb_numbers)
	{
		j = 0;
		counter = 1;
		while (j < nb_numbers)
		{
			if (array[j] < array[i])
				counter++;
			j++;
		}
		new_array[i] = counter;
		i++;
	}
	new_array[i] = 0;
	return (free(array), new_array);
}

int	check_array(long long *array_int, int argc)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	j = 1;
	counter = 0;
	while (counter < argc - 1)
	{
		if (array_int[counter] < INT_MIN || array_int[counter] > INT_MAX)
			return (1);
		counter++;
	}
	while (i < argc - 2)
	{
		while (j < argc - 1)
		{
			if (array_int[j] == array_int[i])
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

long long	*parse_args(int argc, char **argv)
{
	long long	*array_int;
	long long	i;

	i = 0;
	if (argc > 2)
		array_int = int_args(argc, argv);
	if (argc == 2)
	{
		argc = nb_split2(argv[1], ' ') + 1;
		array_int = string_arg(argv);
	}
	if (!array_int)
		return (NULL);
	if (check_array(array_int, argc) == 1)
	{
		free(array_int);
		return (NULL);
	}
	return (array_int);
}

int	main(int argc, char **argv)
{
	long long	*array_a;
	long long	*array_b;

	if (argc < 2)
		return (0);
	array_a = parse_args(argc, argv);
	if (!array_a)
		return (write(2, "Error\n", 6));
	if (argc == 2)
		argc = nb_split2(argv[1], ' ') + 1;
	if (array_is_sorted(array_a, argc))
		return (free(array_a), 0);
	array_b = ft_calloc(argc, sizeof(long long));
	array_a = change_numbers(array_a, argc - 1);
	if (!array_a || !array_b)
		return (free(array_a), 1);
	if (argc <= 24)
		sorting_small(array_a, array_b, argc);
	else
		sorting_algo(array_a, array_b);
	free(array_a);
	free(array_b);
	return (0);
}

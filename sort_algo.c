/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdero <gdero@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:20:12 by gdero             #+#    #+#             */
/*   Updated: 2024/03/15 14:20:25 by gdero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_algo(long long *array_a, long long *array_b)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	j = 0;
	counter = 0;
	while (array_a[counter])
		counter++;
	while (!is_sorted(array_a, 1))
	{
		i = 0;
		while (i < counter)
		{
			if ((array_a[0] >> j) % 2 == 0)
				push(array_a, array_b, 1);
			else
				rotate(array_a, 1);
			i++;
		}
		while (array_b[0] != 0)
			push(array_b, array_a, 2);
		j++;
	}
	return ;
}

void	sort_three(long long *array)
{
	if (array[0] == 1 && array[1] == 3)
	{
		swap(array, 1);
		rotate(array, 1);
	}
	if (array[0] == 2 && array[1] == 1)
		swap(array, 1);
	if (array[0] == 2 && array[1] == 3)
		inverted_rotate(array, 1);
	if (array[0] == 3 && array[1] == 1)
		rotate(array, 1);
	if (array[0] == 3 && array[1] == 2)
	{
		swap(array, 1);
		inverted_rotate(array, 1);
	}
	return ;
}

void	sorting_small(long long *array_a, long long *array_b, int argc)
{
	if (argc == 3)
		rotate(array_a, 1);
	if (argc == 4)
		sort_three(array_a);
	if (argc > 4)
		sort_twenty_four_or_less(array_a, array_b);
	return ;
}

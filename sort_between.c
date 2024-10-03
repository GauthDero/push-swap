/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_between.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdero <gdero@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:20:34 by gdero             #+#    #+#             */
/*   Updated: 2024/03/15 14:20:47 by gdero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_array(long long *array_a, long long *array_b, int middle)
{
	int	i;

	i = 0;
	while (i < middle)
	{
		if (array_a[0] <= middle)
		{
			push(array_a, array_b, 1);
			i++;
		}
		else
			rotate(array_a, 1);
	}
	return ;
}

bool	is_sorted(long long *array, int check)
{
	int	i;

	i = 0;
	while (array[i + 1] != 0)
	{
		if (check == 1)
		{
			if (array[i] != array[i + 1] - 1)
				return (false);
			i++;
		}
		if (check == 2)
		{
			if (array[i] != array[i + 1] + 1)
				return (false);
			i++;
		}
	}
	return (true);
}

void	shenanigans(long long *array_a, long long *array_b, int max)
{
	while (!is_sorted(array_a, 1) || !is_sorted(array_b, 2))
	{
		if (array_a[0] > array_a[1] && array_b[0] < array_b[1] \
		&& array_b[0] != 1 && array_a[0] != max)
			ss(array_a, array_b);
		else if (array_a[0] > array_a[1] && array_a[0] != max)
			swap(array_a, 1);
		else if (array_b[0] < array_b[1] && array_b[0] != 1)
			swap(array_b, 2);
		else if (!is_sorted(array_a, 1) && !is_sorted(array_b, 2))
			rr(array_a, array_b);
		else if (is_sorted(array_a, 1) || array_b[0] == 1)
			rotate(array_b, 2);
		else if (is_sorted(array_b, 2) || array_a[0] == max)
			rotate(array_a, 1);
	}
}

void	sort_twenty_four_or_less(long long *array_a, long long *array_b)
{
	int	middle;
	int	max;

	middle = 0;
	while (array_a[middle] != 0)
		middle++;
	max = middle;
	middle = middle / 2;
	divide_array(array_a, array_b, middle);
	shenanigans(array_a, array_b, max);
	max = 0;
	while (max < middle)
	{
		push(array_b, array_a, 2);
		max++;
	}
}

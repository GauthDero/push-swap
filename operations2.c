/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdero <gdero@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:18:50 by gdero             #+#    #+#             */
/*   Updated: 2024/03/15 14:19:02 by gdero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(long long *array_a, long long *array_b)
{
	int	check;

	check = 0;
	rotate(array_a, check);
	rotate(array_b, check);
	ft_printf("rr\n");
	return ;
}

void	inverted_rotate(long long *array, int check)
{
	long long	i;
	long long	temp;

	i = 0;
	while (array[i])
		i++;
	i--;
	temp = array[i];
	while (i >= 0)
	{
		array[i] = array[i - 1];
		i--;
	}
	array[0] = temp;
	if (check == 1)
		ft_printf("rra\n");
	if (check == 2)
		ft_printf("rrb\n");
	return ;
}

void	rrr(long long *array_a, long long *array_b)
{
	int	check;

	check = 0;
	inverted_rotate(array_a, check);
	inverted_rotate(array_b, check);
	ft_printf("rrr\n");
	return ;
}

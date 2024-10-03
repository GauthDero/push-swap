/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdero <gdero@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:18:29 by gdero             #+#    #+#             */
/*   Updated: 2024/03/15 14:18:44 by gdero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(long long *array, int check)
{
	long long	temp;

	temp = array[0];
	array[0] = array[1];
	array[1] = temp;
	if (check == 1)
		ft_printf("sa\n");
	if (check == 2)
		ft_printf("sb\n");
	return ;
}

void	ss(long long *array_a, long long *array_b)
{
	int	check;

	check = 0;
	swap(array_a, check);
	swap(array_b, check);
	ft_printf("ss\n");
	return ;
}

void	rotate(long long *array, int check)
{
	long long	i;
	long long	temp;

	i = 0;
	temp = array[0];
	while (array[i] != 0)
	{
		array[i] = array[i + 1];
		i++;
	}
	array[i - 1] = temp;
	if (check == 1)
		ft_printf("ra\n");
	if (check == 2)
		ft_printf("rb\n");
	return ;
}

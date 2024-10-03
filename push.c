/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdero <gdero@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:20:13 by gdero             #+#    #+#             */
/*   Updated: 2024/03/06 14:20:31 by gdero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_empty(long long *array_a, long long *array_b)
{
	long long	i;
	long long	j;

	i = 0;
	j = 0;
	array_a[0] = array_b[0];
	while (array_b[i])
		i++;
	while (j < i - 1)
	{
		array_b[j] = array_b[j + 1];
		j++;
	}
	ft_printf("pa\n");
	return ;
}

void	make_room_and_push(long long *array_1, long long *array_2)
{
	long long	i;

	i = 0;
	while (array_2[i])
		i++;
	while (i > 0)
	{
		if (array_2[0] == 0)
			break ;
		array_2[i] = array_2[i - 1];
		i--;
	}
	array_2[0] = array_1[0];
	return ;
}

void	push(long long *array_1, long long *array_2, int check)
{
	long long	i;
	long long	j;

	i = 0;
	j = 0;
	if (array_2[0] == 0 && check == 2)
	{
		a_empty(array_2, array_1);
		return ;
	}
	make_room_and_push(array_1, array_2);
	while (array_1[i])
		i++;
	while (j < i - 1)
	{
		array_1[j] = array_1[j + 1];
		j++;
	}
	array_1[j] = 0;
	if (check == 1)
		ft_printf("pb\n");
	if (check == 2)
		ft_printf("pa\n");
	return ;
}

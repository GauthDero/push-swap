/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdero <gdero@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:19:47 by gdero             #+#    #+#             */
/*   Updated: 2024/04/01 17:13:45 by gdero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

long		ft_atoi_2(const char *str);
long long	*change_numbers(long long *array, int nb_numbers);
bool		array_is_sorted(long long *array_a, int argc);
long long	*parse_args(int argc, char **argv);
long		nb_split2(char const *string, char sep);
int			check_array(long long *array_int, int argc);
long long	*int_args(int argc, char **argv);
long long	*string_arg(char **argv);
void		swap(long long *array, int check);
void		ss(long long *array_a, long long *array_b);
void		push(long long *array_1, long long *array_2, int check);
void		rotate(long long *array, int check);
void		rr(long long *array_a, long long *array_b);
void		inverted_rotate(long long *array_a, int check);
void		rrr(long long *array_a, long long *array_b);
void		sorting_small(long long *array_a, long long *array_b, int argc);
void		sort_three(long long *array_a);
void		sorting_algo(long long *array_a, long long *array_b);
void		sort_twenty_four_or_less(long long *array_a, long long *array_b);
bool		is_sorted(long long *array, int check);
void		divide_array(long long *array_a, long long *array_b, int middle);
bool		check_string(char **argv);
bool		check_ints(int argc, char **argv);
void		fill_array(long long *array_int, char **numbers);
void		a_empty(long long *array_a, long long *array_b);
void		shenanigans(long long *array_a, long long *array_b, int max);
void		make_room_and_push(long long *array_1, long long *array_2);
bool		check_null(int argc, char **argv);

#endif

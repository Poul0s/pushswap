/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extreme_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:27:10 by psalame           #+#    #+#             */
/*   Updated: 2023/11/25 14:21:32 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_extreme_value(t_pile *pile, int value)
{
	t_bool	is_min;
	t_bool	is_max;
	size_t	i;

	is_min = TRUE;
	is_max = TRUE;
	i = 0;
	while (i < pile->size)
	{
		if (pile->data[i].nb < value)
			is_min = FALSE;
		if (pile->data[i].nb > value)
			is_max = FALSE;
		i++;
	}
	return (is_min || is_max);
}

size_t	get_max_value_index(t_pile *pile)
{
	size_t	i;
	size_t	max;

	i = 0;
	max = 0;
	while (i < pile->size)
	{
		if (pile->data[i].nb > pile->data[max].nb)
			max = i;
		i++;
	}
	return (max);
}

size_t	get_min_value_index(t_pile *pile)
{
	size_t	i;
	size_t	min;

	i = 0;
	min = 0;
	while (i < pile->size)
	{
		if (pile->data[i].nb < pile->data[min].nb)
			min = i;
		i++;
	}
	return (min);
}

size_t	get_max_value_below_index(t_pile *pile, int value_max)
{
	size_t	i;
	ssize_t	max;
	int		nb;

	i = 0;
	max = -1;
	while (i < pile->size)
	{
		nb = pile->data[i].nb;
		if (max == -1 && nb < value_max)
			max = i;
		else if (max != -1 && nb > pile->data[max].nb && nb < value_max)
			max = i;
		i++;
	}
	return (max);
}

// todo maybe if no value found : send min value (and check failed case)
size_t	get_min_value_after_index(t_pile *pile, int value_min)
{
	size_t	i;
	ssize_t	min;
	int		nb;

	i = 0;
	min = -1;
	while (i < pile->size)
	{
		nb = pile->data[i].nb;
		if (min == -1 && nb > value_min)
			min = i;
		else if (min != -1 && nb < pile->data[min].nb && nb > value_min)
			min = i;
		i++;
	}
	return (min);
}

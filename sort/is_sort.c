/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:10:24 by psalame           #+#    #+#             */
/*   Updated: 2023/11/25 00:47:27 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_sort(t_pile *pile)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (pile->size == 0)
		return (TRUE);
	while (i < pile->size - 1)
	{
		j = i + 1;
		while (j < pile->size)
		{
			if (pile->data[i].nb < pile->data[j].nb)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

t_bool	is_cyclic_sort(t_pile *pile)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (pile->size == 0)
		return (TRUE);
	while (i < pile->size - 1)
	{
		j = i + 1;
		while (j < pile->size)
		{
			if (pile->data[i].nb < pile->data[j].nb)
			{
				if (get_min_value_index(pile) != i || get_max_value_index(pile) != j)
					return (FALSE);
				else
					break;
			}
			j++;
		}
		i++;
	}
	return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:10:24 by psalame           #+#    #+#             */
/*   Updated: 2023/11/18 03:10:37 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_sort(t_pile *pile_a, t_pile *pile_b)
{
	size_t	i;
	size_t	j;

	if (pile_b->size != 0)
		return (FALSE);
	i = 0;
	while (i < pile_a->size - 1)
	{
		j = i + 1;
		while (j < pile_a->size)
		{
			if (pile_a->data[i] < pile_a->data[j])
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

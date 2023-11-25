/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calcul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:13:01 by psalame           #+#    #+#             */
/*   Updated: 2023/11/25 14:30:30 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	calcul_go_top_cost(t_pile *pile, size_t i)
{
	unsigned int	cost;

	cost = 0;
	if (i <= pile->size / 2)
		cost = i + 1;
	else
		cost = pile->size - i - 1;
	return (cost);
}

t_stepcost	calcul_better_place(t_pile *a, t_pile *b, size_t i)
{
	size_t	b_target;

	if (is_extreme_value(b, a->data[i].nb))
	{
		b_target = get_max_value_index(b);
		return (get_best_mouvment(a, b, i, b_target));
	}
	else
	{
		b_target = get_max_value_below_index(b, a->data[i].nb);
		return (get_best_mouvment(a, b, i, b_target));
	}
}

size_t	calcul_push_cost(t_pile *a, t_pile *b)
{
	size_t			i;
	size_t			i_min;
	t_stepcost		best;

	i = 0;
	i_min = 0;
	while (i < a->size)
	{
		best = calcul_better_place(a, b, i);
		a->data[i].cost = best.cost;
		if (a->data[i].cost <= a->data[i_min].cost)
			i_min = i;
		i++;
	}
	return (i_min);
}

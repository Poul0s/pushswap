/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_best_mouvment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:28:03 by psalame           #+#    #+#             */
/*   Updated: 2023/11/25 14:16:47 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stepcost	get_best_mouvment(t_pile *a, t_pile *b, size_t i, size_t j)
{
	t_stepcost	best;

	best.cost = MAX((a->size - i - 1) * (1 + (a->size > b->size) * 0.1), (b->size - j - 1) * (1 + (a->size < b->size) * 0.1));
	best.a_direction = 1;
	best.a_steps = a->size - i - 1;
	best.b_steps = b->size - j - 1;
	if (MAX(i + 1, j + 1) < best.cost)
	{
		best.cost = MAX((i + 1) * (1 + (a->size > b->size) * 0.1), (j + 1) * (1 + (a->size < b->size) * 0.1));
		best.a_direction = -1;
		best.a_steps = i + 1;
		best.b_steps = j + 1;
	}
	best.b_direction = best.a_direction;
	if (calcul_go_top_cost(a, i) + calcul_go_top_cost(b, j) < best.cost)
	{
		best.a_steps = calcul_go_top_cost(a, i);
		best.b_steps = calcul_go_top_cost(b, j);
		best.cost = best.a_steps * (1 + (a->size > b->size) * 0.1) + (best.b_steps) * (1 + (a->size < b->size) * 0.1);
		best.a_direction = 1 - ((i <= a->size / 2) * 2);
		best.b_direction = 1 - ((j <= b->size / 2) * 2);
	}
	return (best);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_best_mouvment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:28:03 by psalame           #+#    #+#             */
/*   Updated: 2023/11/25 18:03:13 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calcul_cost_coef(t_stepcost *stepcost, t_pile *a, t_pile *b)
{
	unsigned int	a_cost_coef;
	unsigned int	b_cost_coef;

	a_cost_coef = stepcost->a_steps * (1 + (a->size > b->size) * 0.2);
	b_cost_coef = stepcost->b_steps * (1 + (a->size < b->size) * 0.2);
	if (stepcost->a_direction == stepcost->b_direction)
		stepcost->cost = max(a_cost_coef, b_cost_coef);
	else
		stepcost->cost = a_cost_coef + b_cost_coef;
}

t_stepcost	get_best_mouvment(t_pile *a, t_pile *b, size_t i, size_t j)
{
	t_stepcost	best;

	best.a_direction = 1;
	best.b_direction = 1;
	best.a_steps = a->size - i - 1;
	best.b_steps = b->size - j - 1;
	calcul_cost_coef(&best, a, b);
	if (max(i + 1, j + 1) < best.cost)
	{
		best.a_direction = -1;
		best.b_direction = -1;
		best.a_steps = i + 1;
		best.b_steps = j + 1;
		calcul_cost_coef(&best, a, b);
	}
	best.b_direction = best.a_direction;
	if (calcul_go_top_cost(a, i) + calcul_go_top_cost(b, j) < best.cost)
	{
		best.a_steps = calcul_go_top_cost(a, i);
		best.b_steps = calcul_go_top_cost(b, j);
		best.a_direction = 1 - ((i <= a->size / 2) * 2);
		best.b_direction = 1 - ((j <= b->size / 2) * 2);
		calcul_cost_coef(&best, a, b);
	}
	return (best);
}

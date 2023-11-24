/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calcul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:13:01 by psalame           #+#    #+#             */
/*   Updated: 2023/11/24 21:00:58 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	calcul_go_top_cost(t_pile *pile, size_t i)
{
	unsigned int	cost;

	cost = 0;
	if (i < pile->size / 2)
		cost = i + 1;
	else
		cost = pile->size - i - 1;
	return (cost);
}

t_stepcost	*get_best_mouvment(t_pile *a, t_pile *b, size_t i, size_t j)
{
	t_stepcost	*best;

	best = malloc(sizeof(t_stepcost));
	if (best == NULL)
		return (NULL);
	best->cost = MAX(a->size - i - 1, (b->size - j - 1));
	best->a_direction = 1;
	best->a_steps = a->size - i - 1;
	best->b_steps = b->size - j - 1;
	if (MAX(i + 1, j + 1) < best->cost)
	{
		best->cost = MAX(i + 1, (j + 1));
		best->a_direction = -1;
		best->a_steps = i + 1;
		best->b_steps = j + 1;
	}
	best->b_direction = best->a_direction;
	if (calcul_go_top_cost(a, i) + calcul_go_top_cost(b, j) < best->cost)
	{
		best->a_steps = calcul_go_top_cost(a, i);
		best->b_steps = calcul_go_top_cost(b, j);
		best->cost = best->a_steps + (best->b_steps);
		best->a_direction = 1 - ((i < a->size / 2) * 2);
		best->b_direction = 1 - ((j < b->size / 2) * 2);
	}
	return (best);
}

t_stepcost	*calcul_better_place(t_pile *a, t_pile *b, size_t i)
{
	if (is_extreme_value(b, a->data[i].nb))
		return (get_best_mouvment(a, b, i, get_max_value_index(b)));
	else
		return (get_best_mouvment(a, b, i, get_max_value_below_index(b, a->data[i].nb)));
}

size_t	calcul_push_cost(t_pile *a, t_pile *b, t_list **actions)
{
	size_t			i;
	size_t			i_min;
	t_stepcost		*best;

	i = 0;
	i_min = 0;
	while (i < a->size)
	{
		best = calcul_better_place(a, b, i);
		if (best == NULL)
			ft_error(a, b, actions);
		a->data[i].cost = best->cost;
		if (a->data[i].cost <= a->data[i_min].cost)
			i_min = i;
		i++;
		free(best);
	}
	return (i_min);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:02:03 by psalame           #+#    #+#             */
/*   Updated: 2023/11/25 18:10:08 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_pilea_index_at_top(t_pile *a, t_pile *b, size_t i, t_list **act)
{
	size_t	move_nb;
	t_bool	reverse;

	if (i <= a->size / 2)
	{
		reverse = TRUE;
		move_nb = i + 1;
	}
	else
	{
		reverse = FALSE;
		move_nb = a->size - i - 1;
	}
	while (move_nb != 0)
	{
		do_action(ra + (reverse * 2), act, a, b);
		move_nb--;
	}
}

void	push_efficient(t_pile *a, t_pile *b, t_list **actions, size_t to_push)
{
	t_stepcost	mouvment;

	mouvment = calcul_better_place(a, b, to_push);
	if (mouvment.a_direction == mouvment.b_direction)
	{
		while (min(mouvment.a_steps, mouvment.b_steps) > 0)
		{
			do_action(rr + (mouvment.a_direction == -1), actions, a, b);
			mouvment.a_steps--;
			mouvment.b_steps--;
		}
	}
	while (mouvment.a_steps-- > 0)
		do_action(ra + ((mouvment.a_direction == -1) * 2), actions, a, b);
	while (mouvment.b_steps-- > 0)
		do_action(rb + ((mouvment.b_direction == -1) * 2), actions, a, b);
	do_action(pb, actions, a, b);
}

void	push_b_into_a_sorted(t_pile *a, t_pile *b, t_list **actions)
{
	ssize_t	a_target;

	while (b->size != 0)
	{
		a_target = get_min_value_after_index(a, b->data[b->size - 1].nb);
		if (a_target != -1)
			set_pilea_index_at_top(a, b, a_target, actions);
		else
			set_pilea_index_at_top(a, b, get_min_value_index(a), actions);
		do_action(pa, actions, a, b);
	}
	while (get_max_value_index(a) != 0)
	{
		if (get_max_value_index(a) < a->size / 2)
			do_action(rra, actions, a, b);
		else
			do_action(ra, actions, a, b);
	}
}

void	big_sort(t_pile *a, t_pile *b, t_list **actions)
{
	size_t	to_push;

	do_action(pb, actions, a, b);
	do_action(pb, actions, a, b);
	while (a->size > 3 && !is_cyclic_sort(a))
	{
		to_push = calcul_push_cost(a, b);
		push_efficient(a, b, actions, to_push);
	}
	if (!is_cyclic_sort(a))
		sort_three(a, b, actions);
	push_b_into_a_sorted(a, b, actions);
}

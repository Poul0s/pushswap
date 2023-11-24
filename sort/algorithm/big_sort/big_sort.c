/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:02:03 by psalame           #+#    #+#             */
/*   Updated: 2023/11/24 20:36:16 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// algo : https://medium.com/@ayogun/push-swap-c1f5d2d41e97

void	set_pileb_index_at_top(t_pile *a, t_pile *b, size_t i, t_list **act)
{
	size_t	move_nb;
	t_bool	reverse;

	reverse = FALSE;
	move_nb = b->size - i - 1;
	if (i < b->size / 2)
	{
		reverse = TRUE;
		move_nb = i + 1;
	}
	while (move_nb != 0)
	{
		do_action(rb + reverse * 2, act, a, b);
		move_nb--;
	}
}

void	set_pilea_index_at_top(t_pile *a, t_pile *b, size_t i, t_list **act)
{
	size_t	move_nb;
	t_bool	reverse;

	if (i < a->size / 2)
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

t_bool	is_element_extreme_of_pile(t_pile *pile, int element)
{
	int		min;
	int		max;
	size_t	i;

	if (pile->size == 0)
		return (TRUE);
	i = 1;
	min = pile->data[0].nb;
	max = pile->data[0].nb;
	while (i < pile->size)
	{
		if (pile->data[i].nb > max)
			max = pile->data[i].nb;
		if (pile->data[i].nb < min)
			min = pile->data[i].nb;
		i++;
	}
	return (element < min || element > max);
}

void	push_efficient(t_pile *a, t_pile *b, t_list **actions, size_t to_push)
{
	t_stepcost	*mouvment;
	
	mouvment = calcul_better_place(a, b, to_push);
	if (mouvment == NULL)
		ft_error(a, b, actions);
	if (mouvment->a_direction == mouvment->b_direction)
	{
		while (MIN(mouvment->a_steps, mouvment->b_steps) > 0)
		{
			do_action(rr + (mouvment->a_direction == -1), actions, a, b);
			mouvment->a_steps--;
			mouvment->b_steps--;
		}
	}
	while (mouvment->a_steps-- > 0)
		do_action(ra + ((mouvment->a_direction == -1) * 2), actions, a, b);
	while (mouvment->b_steps-- > 0)
		do_action(rb + ((mouvment->b_direction == -1) * 2), actions, a, b);
	do_action(pb, actions, a, b);
	free(mouvment);
}


void	big_sort(t_pile *a, t_pile *b, t_list **actions)
{
	size_t	to_push;

	do_action(pb, actions, a, b);
	do_action(pb, actions, a, b);
	while (a->size > 3 && !is_sort(a)) // && !is_sort(a) // todo or cycled sorted
	{
		to_push = calcul_push_cost(a, b, actions);
		push_efficient(a, b, actions, to_push);
	}
	if (!is_sort(a)) // todo or cycled sorted
		sort_three(a, b, actions);
	while (b->size != 0)
	{
		if (get_min_value_after_index(a, b->data[b->size - 1].nb) != ((size_t) -1))
			set_pilea_index_at_top(a, b, get_min_value_after_index(a, b->data[b->size - 1].nb), actions);
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
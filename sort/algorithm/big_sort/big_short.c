/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_short.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:02:03 by psalame           #+#    #+#             */
/*   Updated: 2023/11/23 18:44:40 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// algo : https://medium.com/@ayogun/push-swap-c1f5d2d41e97

// when push b : si c'est le nb le plus petit ou le plus grand de la pile B, il doit etre au dessus du nombre le plus grand de B 

void	set_pileb_index_at_top(t_pile *a, t_pile *b, size_t i, t_list **act)
{
	size_t	move_nb;
	t_bool	reverse;

	reverse = FALSE;
	move_nb = b->size - i - 1;
	if (i < b->size / 2)
	{
		reverse = TRUE;
		move_nb = i + i;
	}
	while (move_nb != 0)
	{
		do_action(rb + reverse * 2, act, a, b);
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

void	push_efficient(pile_a, pile_b, actions, to_push)
{
	
}


void	big_sort(t_pile *pile_a, t_pile *pile_b, t_list **actions)
{
	size_t	to_push;

	do_action(pb, actions, pile_a, pile_b);
	do_action(pb, actions, pile_a, pile_b);
	while (pile_a->size > 3) // todo or cyclic sorted
	{
		to_push = calcul_push_cost(pile_a, pile_b, actions);
		push_efficient(pile_a, pile_b, actions, to_push);
	}
	return ;
}
